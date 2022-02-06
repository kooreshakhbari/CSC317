#include "AABBTree.h"

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>

#include "insert_box_into_box.h"
using namespace std;

typedef pair<int, std::shared_ptr<Object>> priority_pair;

// Make this a global variable to easily use in the sort function
int longest_axis_id;

bool sort_function(std::shared_ptr<Object> &obj1,
                   std::shared_ptr<Object> &obj2) {
  return obj1->box.center()[longest_axis_id] <
         obj2->box.center()[longest_axis_id];
};

AABBTree::AABBTree(const std::vector<std::shared_ptr<Object>> &objects,
                   int a_depth)
    : depth(std::move(a_depth)), num_leaves(objects.size()) {
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  // Right and left object vectors
  std::vector<std::shared_ptr<Object>> left_objects;
  std::vector<std::shared_ptr<Object>> right_objects;
  if (num_leaves == 0) return;

  if (num_leaves == 1) {
    this->left = objects[0];
    insert_box_into_box(objects[0]->box, this->box);
    this->right = nullptr;
    return;
  } else if (num_leaves == 2) {
    this->left = objects[0];
    insert_box_into_box(objects[0]->box, this->box);
    this->right = objects[1];
    insert_box_into_box(objects[1]->box, this->box);
    return;
  }

  // Insert all the boxes into the main box and then from there find the longest
  // axis of the parent box
  for (auto object : objects) {
    insert_box_into_box(object->box, this->box);
  }

  Eigen::RowVector3d length_all_axis =
      this->box.max_corner - this->box.min_corner;

  double longest_axis_length = -1 * std::numeric_limits<double>::infinity();

  // Find the longest axis
  for (int i = 0; i < length_all_axis.size(); i++) {
    if (length_all_axis[i] > longest_axis_length) {
      longest_axis_length = length_all_axis[i];
      longest_axis_id = i;
    }
  }

  // Cant use priority queue as its to slow...
  // priority_queue<priority_pair, vector<priority_pair>,
  // greater<priority_pair>>
  //     p_queue;

  // for (auto object : objects) {
  //   p_queue.push(make_pair(object->box.center()[longest_axis_id], object));
  // }
  // int mid = num_leaves / 2;
  // int i = 0;
  // while (!p_queue.empty()) {
  //   priority_pair top_pair = p_queue.top();
  //   p_queue.pop();
  //   if (i < mid) {
  //     lo.push_back(top_pair.second);
  //   } else {
  //     ro.push_back(top_pair.second);
  //   }

  //   i++;
  // }

  std::vector<std::shared_ptr<Object>> sorted_obj = objects;
  // Sort it all by using the sort function I wrote
  std::sort(sorted_obj.begin(), sorted_obj.end(), sort_function);

  // Start inserting into the left and right based on the len of objects that we
  // have
  left_objects.insert(left_objects.begin(), sorted_obj.begin(),
                      sorted_obj.begin() + objects.size() / 2);
  right_objects.insert(right_objects.begin(),
                       sorted_obj.begin() + objects.size() / 2,
                       sorted_obj.end());

  // Insert
  this->left = std::make_shared<AABBTree>(left_objects, a_depth + 1);
  this->right = std::make_shared<AABBTree>(right_objects, a_depth + 1);
}
