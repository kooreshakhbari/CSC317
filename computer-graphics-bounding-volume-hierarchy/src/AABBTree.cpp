#include "AABBTree.h"

#include <algorithm>

#include "insert_box_into_box.h"

int longest_axis_id = -1;

bool sort_function(std::shared_ptr<Object> &obj1,
                   std::shared_ptr<Object> &obj2) {
  return obj1->box.center()[longest_axis_id] <
         obj2->box.center()[longest_axis_id];
};

AABBTree::AABBTree(const std::vector<std::shared_ptr<Object> > &objects,
                   int a_depth)
    : depth(std::move(a_depth)), num_leaves(objects.size()) {
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

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
  int longest_axis_length = -1 * std::numeric_limits<double>::infinity();

  for (int i = 0; i < length_all_axis.size(); i++) {
    if (length_all_axis[i] > longest_axis_length) {
      longest_axis_id = i;
    }
  }

  std::vector<std::shared_ptr<Object> > sorted_obj = objects;
  sort(sorted_obj.begin(), sorted_obj.end(), sort_function);
}
