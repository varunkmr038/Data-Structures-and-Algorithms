
// Time: O(N) Space: O(N) Using map
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

  unordered_map<ListNode*, bool> mp;

  while (headA != NULL) {

    mp[headA] = 1;
    headA = headA->next;
  }

  while (headB != NULL) {
    if (mp.count(headB)) return headB;

    headB = headB->next;
  }

  return NULL;
}

// ----------------------------------------------------------------------------------

int length(ListNode* head) {

  int len = 0;

  while (head != NULL) {
    len++;
    head = head->next;
  }

  return len;

}
// Time: O(N) Space: O(1) computing len
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {

  int len1 = length(head1);
  int len2 = length(head2), d;

  if (len1 > len2) {
    d = len1 - len2;
    while (d--)head1 = head1->next;

  }

  else {
    d = len2 - len1;
    while (d--)head2 = head2->next;
  }

  while (head1 != NULL and head2 != NULL) {

    if (head1 == head2) return head1;

    head1 = head1->next;
    head2 = head2->next;

  }
  return NULL;
}

// -------------------------------------------------------------------------------------

// Time: O(N) Space: O(1)
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {

  if (head1 == NULL or head2 == NULL ) return NULL;

  ListNode* d1 = head1;
  ListNode* d2 = head2;
  while (d1 != d2) {

    if (d1 == NULL) d1 = head2;
    else     d1 = d1->next;

    if (d2 == NULL) d2 = head1;

    else d2 = d2->next;

  }
  return d1;
}