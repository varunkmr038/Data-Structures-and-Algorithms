
// Time: O(N) Space: O(1) using slow fast pointers
ListNode* middleNode(ListNode* head) {

  ListNode* s = head;
  ListNode* f = head;

  while (f != NULL and f->next != NULL) {
    f = f->next->next;
    s = s->next;
  }

  return s;
}