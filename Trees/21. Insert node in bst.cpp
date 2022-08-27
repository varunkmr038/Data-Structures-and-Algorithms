

//  Time: O(LogN) Space: O(LogN) Using Simple Comparisons recursive
TreeNode* insertIntoBST(TreeNode* root, int val) {

   if (root == NULL) {
      TreeNode* newNode = new TreeNode(val);
      return newNode;
   }

   if (val > root->val) root->right = insertIntoBST(root->right, val);
   else root->left = insertIntoBST(root->left, val);

   return root;
}