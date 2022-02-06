#include "point_AABBTree_squared_distance.h"

#include <queue>  // std::priority_queue
using namespace std;

typedef pair<double, std::shared_ptr<Object>> priority_pair;

// Helper function to calculate distance and enter into queue
void calculate_insert_to_q(priority_queue<priority_pair, vector<priority_pair>,
                                          greater<priority_pair>>& p_queue,
                           std::shared_ptr<Object>& node, const double min_sqrd,
                           const double max_sqrd,
                           const Eigen::RowVector3d& query) {
  double distance = point_box_squared_distance(query, node->box);
  if (distance < max_sqrd && distance >= min_sqrd) {
    p_queue.push(make_pair(distance, node));
  }
}

bool point_AABBTree_squared_distance(const Eigen::RowVector3d& query,
                                     const std::shared_ptr<AABBTree>& root,
                                     const double min_sqrd,
                                     const double max_sqrd, double& sqrd,
                                     std::shared_ptr<Object>& descendant) {
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here

  // Min heap
  priority_queue<priority_pair, vector<priority_pair>, greater<priority_pair>>
      p_queue;
  double distance = point_box_squared_distance(query, root->box);

  if (distance >= max_sqrd || distance < min_sqrd) {
    return false;
  }

  p_queue.push(make_pair(distance, root));

  while (!p_queue.empty()) {
    priority_pair curr_min_element = p_queue.top();
    // pop at the start of the loop else if you pop at the end it all breaks...
    p_queue.pop();

    // Typecast
    std::shared_ptr<AABBTree> top_node =
        std::dynamic_pointer_cast<AABBTree>(curr_min_element.second);

    // We are at a leaf
    if (!top_node) {
      if (curr_min_element.first >= min_sqrd) {
        sqrd = curr_min_element.first;
        descendant = curr_min_element.second;
        return true;
      }
      continue;
    }

    if (top_node->left) {
      calculate_insert_to_q(p_queue, top_node->left, min_sqrd, max_sqrd, query);
    }

    if (top_node->right) {
      calculate_insert_to_q(p_queue, top_node->right, min_sqrd, max_sqrd,
                            query);
    }
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
