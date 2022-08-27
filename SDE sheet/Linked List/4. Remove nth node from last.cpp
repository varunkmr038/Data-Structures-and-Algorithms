int length(ListNode* head) {

  int len = 0;

  while (head != NULL) {
    len++;
    head = head->next;
  }

  return len;

}
// Time: O(N) Space: O(1)
ListNode* removeNthFromEnd(ListNode* head, int k) {

  int len = length(head);
  if (len == 1) return NULL;
  if (k == len) return head->next;

  int steps = 1;
  ListNode* temp = head;
  while (steps <= len - k - 1) {

    temp = temp->next;
    steps++;
  }

  temp->next = temp->next->next;

  return head;
}

// -------------------------------------------------------------

// Time: O(N) Space: O(1) One pass soln
ListNode* removeNthFromEnd(ListNode* head, int k) {

  if (head->next == NULL) return NULL;

  int steps = 1;
  ListNode* temp = head;
  ListNode* temp2 = head;
  while (steps <= k) {
    temp = temp->next;
    steps++;
  }

  if (temp == NULL) return head->next;

  while (temp->next != NULL) {
    temp = temp->next;
    temp2 = temp2->next;
  }

  temp2->next = temp2->next->next;

  return head;
}
