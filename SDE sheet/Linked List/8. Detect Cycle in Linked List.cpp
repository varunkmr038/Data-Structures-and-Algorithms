

// Time: O(N) Space: O(1)
bool hasCycle(ListNode *head) {

  ListNode* s = head;
  ListNode* f = head;

  while (f != NULL and f->next != NULL) {

    s = s->next;
    f = f->next->next;

    if (s == f) return 1;
  }
  return 0;
}