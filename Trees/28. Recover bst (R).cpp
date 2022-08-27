
void inorderTraversal(TreeNode* root, vector<int>& inorder) {

  if (root == NULL) return;

  inorderTraversal(root->left, inorder);
  inorder.push_back(root->val);
  inorderTraversal(root->right, inorder);
}

void solve(TreeNode* root, vector<int>& inorder, int& idx) {

  if (root == NULL) return ;

  solve(root->left, inorder, idx);

  root->val = inorder[idx++];

  solve(root->right, inorder, idx);
}

// Time: O(NLogn) Space: O(N) Using inorderd traversal
void recoverTree(TreeNode* root) {

  vector<int> inorder;
  inorderTraversal(root, inorder);
  sort(inorder.begin(), inorder.end());

  int idx = 0;
  solve(root, inorder, idx);

}

// -----------------------------------------------------------------------------


void solve(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& middle, TreeNode*& last) {

  if (root == NULL) return ;

  solve(root->left, prev, first, middle, last);

  // i got the violation of sorted inorder
  if (prev != NULL and root->val < prev->val) {

    // this is first violation
    if (first == NULL) {
      first = prev;
      middle = root;
    }
    else last = root;

  }

  prev = root;
  solve(root->right, prev, first, middle, last);
}

// Time: O(N) Space: O(N) Using inorder traversal
void recoverTree(TreeNode* root) {

  TreeNode* prev = NULL;
  TreeNode* first = NULL;
  TreeNode* middle = NULL;
  TreeNode* last = NULL;

  solve(root, prev, first, middle, last);

  if (first and last) swap(first->val, last->val);
  else if (first and middle) swap(first->val, middle->val); // adjacent nodes swap
}

// we can also do this using morris traversal