//  Time: O(1) Space: O(1) swapping values
void deleteNode(ListNode* node) {

  swap(node->val, node->next->val);
  node->next = node->next->next;
}

// ------------------------------------------------