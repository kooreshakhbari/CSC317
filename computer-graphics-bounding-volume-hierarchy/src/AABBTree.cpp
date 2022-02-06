#include "AABBTree.h"

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>

#include "insert_box_into_box.h"
using namespace std;

typedef pair<int, std::shared_ptr<Object>> priority_pair;

AABBTree::AABBTree(const std::vector<std::shared_ptr<Object>> &objects,
                   int a_depth)
    : depth(std::move(a_depth)), num_leaves(objects.size()) {
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  // Right and left object vectors
  std::vector<std::shared_ptr<Object>> lo;
  std::vector<std::shared_ptr<Object>> ro;

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

  int longest_axis_id = -1;
  double longest_axis_length = -1 * std::numeric_limits<double>::infinity();

  for (int i = 0; i < length_all_axis.size(); i++) {
    if (length_all_axis[i] > longest_axis_length) {
      longest_axis_id = i;
    }
  }

  priority_queue<priority_pair, vector<priority_pair>, greater<priority_pair>>
      p_queue;

  for (auto object : objects) {
    p_queue.push(make_pair(object->box.center()[longest_axis_id], object));
  }
  int mid = num_leaves / 2;
  int i = 0;
  while (!p_queue.empty()) {
    priority_pair top_pair = p_queue.top();
    if (i < mid) {
      lo.push_back(top_pair.second);
    } else {
      ro.push_back(top_pair.second);
    }

    p_queue.pop();
    i++;
  }

  // Insert
  this->left = std::make_shared<AABBTree>(lo, a_depth + 1);
  this->right = std::make_shared<AABBTree>(ro, a_depth + 1);
}
