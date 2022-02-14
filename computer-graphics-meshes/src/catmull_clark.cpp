#include "catmull_clark.h"
#include <unordered_map>
#include <utility>
#include <functional>
#include <vector>
#include <iostream>

// hashing function from
// https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key
struct hash
{
  template <class T1, class T2>
  size_t operator()(const std::pair<T1, T2> &p) const
  {
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

void catmull_clark(
    const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const int num_iters,
    Eigen::MatrixXd &SV,
    Eigen::MatrixXi &SF)
{
  // algorithm from https://en.wikipedia.org/wiki/Catmull%E2%80%93Clark_subdivision_surface
  if (num_iters == 0)
    return;

  // create face points which is an average
  std::vector<Eigen::RowVector3d> face_points = {}, constructed_vertices = {};

  // set a list of neighboring faces
  std::unordered_map<int, std::vector<int>> neighboring_vertices = {};

  // key of edges is an edge, the pair contains the idx of face that shares this edge
  std::unordered_map<std::pair<int, int>, std::pair<int, int>, hash> edges;
  std::vector<Eigen::RowVector3d> edge_shared_faces;

  // construct face_points
  // obtain forward pairs and reverse pairs of all edge points and connect them to faces
  // does step 1, and 2 (partially) from the wikipedia
  for (auto i = 0; i < F.rows(); ++i)
  {
    Eigen::RowVector3d face_point(0, 0, 0);

    for (auto j = 0; j < F.cols(); ++j)
    {
      face_point += V.row(F(i, j));
      neighboring_vertices[F(i, j)].emplace_back(i);

      auto key_forward = std::make_pair(F(i, j), F(i, (j + 1) % F.cols()));
      auto key_backward = std::make_pair(F(i, (j + 1) % F.cols()), F(i, j));

      auto key_forward_val = edges.find(key_forward);
      auto key_backward_val = edges.find(key_backward);

      if (key_forward_val != edges.end())
        edges[key_forward] = {edges[key_forward].first, i};
      else if (key_backward_val != edges.end())
        edges[key_backward] = {edges[key_backward].first, i};
      else
        edges[key_forward] = {i, 0};
    }

    face_points.emplace_back(face_point / F.cols());
  }

  // completes step 2
  for (auto ele : edges)
    edge_shared_faces.emplace_back((face_points[ele.second.first] + face_points[ele.second.second] + V.row(ele.first.first) + V.row(ele.first.second)) / F.cols());

  // step 3: calculate barycenter
  // step 4 (partial): add the barycenter to the SV
  SV.resize(V.rows() + F.rows() + edges.size(), 3);
  int SV_idx = 0;
  for (int i = 0; i < V.rows(); ++i)
  {
    double n_barycenter = neighboring_vertices[i].size();
    auto p_barycenter = V.row(i);
    Eigen::RowVector3d f_barycenter(0, 0, 0), r_barycenter(0, 0, 0);

    for (auto ele : neighboring_vertices[i])
      f_barycenter += (face_points[ele] / n_barycenter);

    for (auto ele : edges)
      if (i == ele.first.first || i == ele.first.second)
        r_barycenter += (V.row(ele.first.first) + V.row(ele.first.second)) / (2.0 * n_barycenter);

    SV.row(SV_idx++) << (f_barycenter + (2.0 * r_barycenter) + (n_barycenter - 3.0) * p_barycenter) / n_barycenter;
  }

  // add remaining to SV
  for (auto i = 0; SV_idx < V.rows() + F.rows(); ++i)
    SV.row(SV_idx++) << face_points[i];

  for (auto i = 0; SV_idx < V.rows() + F.rows() + edges.size(); ++i)
    SV.row(SV_idx++) << edge_shared_faces[i];

  // complete SF
  SF.resize(F.rows() * F.cols(), 4);
  auto SF_idx = 0;

  for (auto i = 0; i < F.rows(); ++i)
    for (auto j = 0; j < F.cols(); ++j)
    {
      auto edge1 = std::make_pair(F(i, j), F(i, (j + 1) % 4));
      auto edge1_reverse = std::make_pair(F(i, (j + 1) % 4), F(i, j));

      auto edge2 = std::make_pair(F(i, j), F(i, (j + 3) % 4));
      auto edge2_reverse = std::make_pair(F(i, (j + 3) % 4), F(i, j));

      auto k1 = 0, k2 = 0, temp_idx = 0;

      for (auto ele : edges)
      {
        if (edge1 == ele.first || ele.first == edge1_reverse)
          k1 = temp_idx;
        if (edge2 == ele.first || ele.first == edge2_reverse)
          k2 = temp_idx;

        ++temp_idx;
      }

      SF.row(SF_idx++) << F(i, j), V.rows() + F.rows() + k1, V.rows() + i, V.rows() + F.rows() + k2;
    }

  catmull_clark(SV, SF, num_iters - 1, SV, SF);
}