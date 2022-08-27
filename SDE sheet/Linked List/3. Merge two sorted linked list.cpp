

// Time: O(N) Space: O(N) Recursion
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

  if (a == NULL) return b;
  if (b == NULL) return a;

  ListNode* newhead;
  if (a->val < b->val) {
    a->next = mergeTwoLists(a->next, b);
    newhead = a;
  }
  else {
    b->next = mergeTwoLists(a, b->next);
    newhead = b;
  }

  return newhead;
}

// -----------------------------------------------------------

// Time: O(N) Space: O(1) Normal iterative merging
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

  if (head1 == NULL) return head2;
  if (head2 == NULL) return head1;

  ListNode* mergehead = NULL; ListNode* temp = NULL;
  if (head1->val < head2->val) {
    mergehead = head1;
    temp = head1;
    head1 = head1->next;
  }
  else {
    mergehead = head2;
    temp = head2;
    head2 = head2->next;
  }

  while (head1 != NULL and head2 != NULL) {
    if (head1->val < head2->val) {
      temp->next = head1;
      head1 = head1->next;
    }
    else {
      temp->next = head2;
      head2 = head2->next;
    }
    temp = temp->next;
  }

  while (head1 != NULL) {
    temp->next = head1;
    temp = temp->next;
    head1 = head1->next;
  }

  while (head2 != NULL) {
    temp->next = head2;
    temp = temp->next;
    head2 = head2->next;
  }

  return mergehead;
}