#include "find_all_intersecting_pairs_using_AABBTrees.h"

#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <algorithm>
#include <list>
using namespace std;

typedef pair<std::shared_ptr<Object>, std::shared_ptr<Object>> list_pair;
void check_and_insert(std::shared_ptr<Object>& nodeA,
                      std::shared_ptr<Object>& nodeB,
                      list<list_pair>& list_pairs) {
  // Generic function to check intersection and insert
  if (box_box_intersect(nodeA->box, nodeB->box)) {
    list_pairs.push_back(make_pair(nodeA, nodeB));
  }
}

void find_all_intersecting_pairs_using_AABBTrees(
    const std::shared_ptr<AABBTree>& rootA,
    const std::shared_ptr<AABBTree>& rootB,
    std::vector<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>>>&
        leaf_pairs) {
  // Create the list as suggested
  list<list_pair> list_pairs;

  if (box_box_intersect(rootA->box, rootB->box)) {
    list_pairs.push_back(make_pair(rootA, rootB));
  }

  while (!list_pairs.empty()) {
    list_pair front_list = list_pairs.front();
    list_pairs.pop_front();

    // Typecast
    std::shared_ptr<AABBTree> first_node =
        std::dynamic_pointer_cast<AABBTree>(front_list.first);
    std::shared_ptr<AABBTree> second_node =
        std::dynamic_pointer_cast<AABBTree>(front_list.second);

    // They arent pointing to AABB so they are leaves (From the lab github
    // readme)
    if (!first_node && !second_node) {
      leaf_pairs.push_back(front_list);
      // leaf_pairs.push_back(make_pair(first_node, second_node));
      continue;
    }

    // None are leaves therefore insert every combination possible
    if (first_node && second_node) {
      if (first_node->left && second_node->right) {
        check_and_insert(first_node->left, second_node->right, list_pairs);
      }
      if (first_node->left && second_node->left) {
        check_and_insert(first_node->left, second_node->left, list_pairs);
      }

      if (first_node->right && second_node->left) {
        check_and_insert(first_node->right, second_node->left, list_pairs);
      }

      if (first_node->right && second_node->right) {
        check_and_insert(first_node->right, second_node->right, list_pairs);
      }

      continue;
    }

    // First node is a leaf.
    if (!first_node) {
      if (second_node->left) {
        check_and_insert(front_list.first, second_node->left, list_pairs);
      }

      if (second_node->right) {
        check_and_insert(front_list.first, second_node->right, list_pairs);
      }
    }
    // Second node is a leaf
    if (!second_node) {
      if (first_node->left) {
        check_and_insert(first_node->left, front_list.second, list_pairs);
      }

      if (first_node->right) {
        check_and_insert(first_node->right, front_list.second, list_pairs);
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
}
