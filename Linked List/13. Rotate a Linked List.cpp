int len(ListNode* head) {

  int len = 0;
  while (head != NULL) {
    head = head->next;
    len++;
  }
  return len;
}

//  Time: O(N) SPace: O(1) Simple iterating
ListNode* rotateRight(ListNode* head, int k) {

  int n = len(head);
  if (n == 0) return head;
  // no rotation required
  k = k % n;
  if (k == 0) return head;

  ListNode* ans = head;
  ListNode* originalHead = head;

  int i = 1;
  while (i < n - k) {
    head = head->next;
    i++;
  }

  ans = head->next;
  ListNode* temp = head->next;
  head->next = NULL;

  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = originalHead;

  return ans;
}
