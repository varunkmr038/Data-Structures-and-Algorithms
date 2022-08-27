

// Time: O(LogN) Space: O(LogN) Using Comparisons on nodes
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

  // assuming p to be smaller
  if (p->val > q->val) return lowestCommonAncestor(root, q, p); // swap the values

  if (root == NULL or root == p or root == q) return root;

  // iam the splitting point
  if (root->val > p->val and root->val < q->val) return root;   //  ---p ---root ----q

  // search in right
  else if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);  // root  ---p -------q

  else return lowestCommonAncestor(root->left, p, q);  // ---p -------q -- root
}