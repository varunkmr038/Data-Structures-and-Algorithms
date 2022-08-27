// Time: O(N) Space: O(N) Simple Loop addition
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;

  int sum = 0, carry = 0, curValue = 0;
  ListNode* ans = new ListNode(0); // dummy
  ListNode* head = ans;

  while (l1 != NULL or l2 != NULL) {

    int x = (l1 != NULL) ? l1->val : 0;
    int y = (l2 != NULL) ? l2->val : 0;

    sum = x + y + carry;
    carry = sum / 10;
    curValue = sum % 10;

    head->next = new ListNode(curValue);
    if (l1) l1 = l1->next;
    if (l2)l2 = l2->next;

    head = head->next;

  }

  //  If there is carry left
  if (carry)
    head->next = new ListNode(carry);

  return ans->next;
}
