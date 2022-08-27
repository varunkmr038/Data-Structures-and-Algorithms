

// Time: O(N) Space: O(Logn)
TreeNode* deleteNode(TreeNode* root, int key) {

   if (root == NULL)return root;

   if (key > root->val) root->right = deleteNode(root->right, key);
   else if (key < root->val) root->left = deleteNode(root->left, key);

   else {

      if (root->left == NULL and root->right == NULL) return NULL;

      else if (root->left != NULL and root->right == NULL) root = root->left;

      else if (root->right != NULL and root->left == NULL) root = root->right;

      else {

         TreeNode* replace = root->right;

         while (replace->left != NULL) replace = replace->left;

         root->val = replace->val;

         root->right = deleteNode(root->right, replace->val);

      }


   }

   return root;
}