
TreeNode* insertNodeInBST(TreeNode* root, int val) {

  if (root == NULL) {
    TreeNode* newNode = new TreeNode(val);
    return newNode;
  }

  if (val > root->val) root->right = insertNodeInBST(root->right, val);
  else root->left = insertNodeInBST(root->left, val);

  return root;
}

// Time: O(N^2) Space: O(N) Brute Simple finding location and creating node
TreeNode* bstFromPreorder(vector<int>& preorder) {
  // just simply inserting the node in bst

  TreeNode* root = NULL;
  for (int i = 0; i < preorder.size(); i++) {
    root = insertNodeInBST(root, preorder[i]);
  }

  return root;
}


// ---------------------------------------------------------------------------


TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end) {

  if (start > end) return NULL;


  int val = preorder[idx++];
  int mid = start;
  for (int i = start; i <= end; i++) {

    if (inorder[i] == val) {
      mid = i;
      break;

    }

  }

  TreeNode* root = new TreeNode(val);

  root->left = solve(preorder, inorder, idx, start, mid - 1);
  root->right = solve(preorder, inorder, idx, mid + 1, end);

  return root;

}

// Time: O(N*Logn) Space: O(N)
TreeNode* bstFromPreorder(vector<int>& preorder) {

  int n = preorder.size();
  //building tree from preorder and inorder

  vector<int> inorder(preorder.begin(), preorder.end());

  sort(inorder.begin(), inorder.end()); // since bst inorder is always sorted
  int idx = 0;
  return solve(preorder, inorder, idx, 0, n - 1);


}

// ---------------------------------------------------------------------------

TreeNode* solve(TreeNode* root, vector<int>& preorder, int& idx, int mn, int mx) {

  if (idx == preorder.size()) return NULL;

  int val = preorder[idx];

  // this not place for cur node
  if (val<mn or val>mx) return NULL;

  // val>=mn and val<=mx so create a node here
  root = new TreeNode(val);
  idx++;

  root->left = solve(root->left, preorder, idx, mn, val);
  root->right = solve(root->right, preorder, idx, val, mx);

  return root;
}


//  Time: O(N) Space: O(N)
TreeNode* bstFromPreorder(vector<int>& preorder) {

  int idx = 0;

  TreeNode* root = NULL;
  int mn = INT_MIN, mx = INT_MAX;
  return solve(root, preorder, idx, mn, mx);

}