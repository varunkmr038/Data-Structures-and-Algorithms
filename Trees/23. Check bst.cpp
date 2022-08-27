

bool solve(TreeNode* root, long long mn = 1LL * INT_MIN - 1, long long mx = 1LL * INT_MAX + 1)
{
  if (root == NULL) return true;

  bool left = solve(root->left, mn, root->val);
  bool right = solve(root->right, root->val, mx);

  if (!left or !right or root->val <= mn or root->val >= mx) return false;

  return true;
}

// Time: O(N) Space: O(N) Using Simple dfs
bool isValidBST(TreeNode* root)
{
  if (root == NULL) return 1;
  return solve(root);
}


// ---------------------------------------------------------------------


bool solve(TreeNode* root, TreeNode*& prev)
{
  if (root == NULL) return true;

  bool left = solve(root->left, prev);
  // since inorder is always sorted
  if (prev != NULL) {
    // agar mai prev inorder se chota hu so iam not bst
    if (root->val <= prev->val) return false;
  }

  prev = root;

  bool right = solve(root->right, prev);

  return (left and right);
}

// Time: O(N) Space: O(N) Using Inorder
bool isValidBST(TreeNode* root)
{
  if (root == NULL) return true;
  TreeNode* prev = NULL;
  return solve(root, prev);
}
