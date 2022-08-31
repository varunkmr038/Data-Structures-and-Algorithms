// Time: O(N) Space: O(N) mappig old address to new
Node* copyRandomList(Node* head) {

  // points old address to new address
  unordered_map<Node*, Node*> mp;
  if (head == NULL) return NULL;

  Node* newHead = new Node(head->val);
  Node* tempOld = head;
  Node* tempNew = newHead;

  while (tempOld != NULL) {

    // mark the new address
    mp[tempOld] = tempNew;

    tempOld = tempOld->next;
    if (tempOld != NULL)tempNew->next = new Node(tempOld->val);

    tempNew = tempNew->next;
  }

  // again interating and filling randome pointers of new list
  tempOld = head;
  tempNew = newHead;

  while (tempOld != NULL) {

    if (tempOld->random != NULL) {
      tempNew->random = mp[tempOld->random];
    }
    tempOld = tempOld->next;
    tempNew = tempNew->next;
  }
  return newHead;
}

// -------------------------------------------------------------------------------------------------


// Time: O(N) Space: O(1) Tweaking the old list
Node* copyRandomList(Node* head) {

  if (head == NULL) return NULL;

  Node* temp = head;

  // Create new list and connect b/ws
  // A--A'--B--B'
  while (temp != NULL) {

    Node* cur = new Node(temp->val);
    cur->next = temp->next;

    temp->next = cur;
    temp = temp->next->next;
  }

  // connect random pointers
  temp = head;
  while (temp != NULL) {
    if (temp->random != NULL)
      temp->next->random = temp->random->next;
    temp = temp->next->next;
  }

  // connect new list and old list
  Node* newHead = head->next;
  temp = head;
  Node* tempNew = newHead;

  while (temp != NULL) {
    temp->next = tempNew->next;

    if (tempNew->next != NULL)
      tempNew->next = tempNew->next->next;

    temp = temp->next;
    tempNew = tempNew->next;
  }

  return newHead;
}