int length(ListNode*& head) {
  int len = 0;
  ListNode*temp = head;
  while (temp != NULL) {
    temp = temp->next;
    len++;
  }
  return len;
}

// Time: O(N) Space: O(N/K) Recursive
ListNode* reverseKGroup(ListNode* head, int k) {

  if (head == NULL or head->next == NULL) return head;

  if (length(head) < k) return head;

  int step = 1;
  ListNode* p = NULL;
  ListNode* c = head;
  ListNode* n;

  while (step <= k and c != NULL) {

    n = c->next;
    c->next = p;
    p = c;
    c = n;
    step++;
  }

  head->next = reverseKGroup(c, k);

  return p;

}

// ----------------------------------------------------------------------------------


int length(ListNode*& head) {
  int len = 0;
  ListNode*temp = head;
  while (temp != NULL) {
    temp = temp->next;
    len++;
  }
  return len;
}

// Time: O(N) Space: O(1)
ListNode* reverseKGroup(ListNode* head, int k) {


  int len = length(head);

  if (len < k) return head;

  ListNode* ans;
  ListNode* poldhead = head;

  for (int i = 0; i < len / k; i++) {

    int step = 1;
    ListNode* p = NULL;
    ListNode* c = head;
    ListNode* n;

    while (step <= k and c != NULL) {

      n = c->next;
      c->next = p;
      p = c;
      c = n;
      step++;
    }

    if (i == 0) {
      ans = p;
      head = c;
      continue;
    }

    poldhead->next = p;
    poldhead = head;
    head = c;
  }

  poldhead->next = head;

  return ans;

}