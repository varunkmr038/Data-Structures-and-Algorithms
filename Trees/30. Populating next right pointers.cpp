//  Time: O(N)  Space: O(N) Using level order traversing
Node* connect(Node* root) {

  if (root == NULL) return root;

  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {

    int sz = q.size();
    for (int i = 0; i < sz; i++) {

      Node* cur = q.front();
      q.pop();

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);

      if (i == (sz - 1)) cur->next = NULL;
      else cur->next = q.front();
    }
  }

  return root;
}

//----------------------------------------------------------------------------


void dfs(Node* root) {

  if (root->left == NULL) return;


  root->left->next = root->right;

  if (root->next != NULL) {
    root->right->next = root->next->left;
  }

  dfs(root->left);
  dfs(root->right);
}


//  Time: O(N)  Space: O(1) Using DFS
Node* connect(Node* root) {

  if (root == NULL) return root;

  dfs(root);
  return root;
}