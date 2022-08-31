// Time: O(N) Space: O(1) using slow and fast pointers
ListNode *detectCycle(ListNode *head) {
  if (!hasCycle(head)) return NULL;

  ListNode* slow = head->next;
  ListNode* fast = head->next->next;
  while (slow != fast) {
    slow = slow->next; fast = fast->next->next;
  }
  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

bool hasCycle(ListNode *head) {
  ListNode* slow = head; ListNode* fast = head;
  while (fast != NULL and fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) return true;

  }
  return false;
}