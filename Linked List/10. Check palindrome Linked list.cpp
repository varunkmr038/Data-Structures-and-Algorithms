int len(ListNode* head) {

  int l = 0;
  while (head != NULL) {
    head = head->next;
    l++;
  }
  return l;
}


// Time: O(N) Space: O(1) using 2 pointers
bool isPalindrome(ListNode* head) {

  ListNode* left;
  ListNode*right;

  int l = len(head);

  ListNode* p = NULL;
  ListNode* c = head;
  ListNode* n;
  int i = 0;
  while (i < l / 2) {

    n = c->next;
    c->next = p;
    p = c;
    c = n;

    i++;
  }

  left = p;

  if (l % 2 == 0) right = c;
  else right = c->next;

  while (left != NULL and right != NULL) {

    if (left->val != right->val) return 0;

    left = left->next;
    right = right->next;
  }

  return 1;
}
