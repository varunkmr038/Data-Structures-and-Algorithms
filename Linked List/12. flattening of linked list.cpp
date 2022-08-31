

// Time: O(N*Logn) Space: O(N) using min heap
Node *flatten(Node *root)
{
  if (root == NULL) return NULL;

  priority_queue < pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>ki> pq;

  Node* prev = NULL;

  while (root != NULL) {
    pq.push({root->data, root});
    root = root->next;
  }

  Node* ans = NULL;

  while (!pq.empty()) {

    auto cur = pq.top();
    pq.pop();

    Node* curNode = cur.second;

    if (prev == NULL) {
      prev = curNode;
      ans = curNode;
    }
    else {
      prev->bottom = curNode;
      prev = curNode;
    }


    if (curNode->bottom) pq.push({curNode->bottom->data, curNode->bottom});

    curNode->next = NULL;
  }

  return ans;
}
