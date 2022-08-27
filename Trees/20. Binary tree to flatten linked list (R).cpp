
void solve(TreeNode* root, TreeNode*& prev) {

   if (root == NULL) return;

   TreeNode* rightChild = root->right;
   if (prev != NULL) prev->right = root;
   prev = root;

   solve(root->left, prev);
   solve(rightChild, prev);

   root->left = NULL;
}

//  Time: O(N) Space: O(N) Using preorder traversal and keeping track of prev
void flatten(TreeNode* root) {

   if (root == NULL) return;

   TreeNode* prev = NULL;
   solve(root, prev);
}

// ---------------------------------------------------------------------



void solve(TreeNode* root, TreeNode*& prev) {

   if (root == NULL) return;

   solve(root->right, prev);
   solve(root->left, prev);

   root->right = prev;
   root->left = NULL;
   prev = root;
}

//  Time: O(N) Space: O(N) Using post order (RLN) traversal and keeping track of prev
void flatten(TreeNode* root) {
   // RLN reverse of preorder (NLR) so jaate samay kaam krna

   if (root == NULL) return;

   TreeNode* prev = NULL;
   solve(root, prev);
}


// -------------------------------------------------------------


// Time: O(N) Space: O(N) Using stacks preorder traversal
void flatten(TreeNode* root) {

   stack<TreeNode*> s;

   if (!root) return;

   s.push(root);

   while (!s.empty()) {

      TreeNode* cur = s.top();
      s.pop();

      if (cur->right != NULL) s.push(cur->right);
      if (cur->left != NULL) s.push(cur->left);

      if (!s.empty())
         cur->right = s.top();

      cur->left = NULL;
   }


}

// --------------------------------------------------------------------------

//  Time: O(N) Space: O(1) Using morris traversal
void flatten(TreeNode* root) {

   if (root == NULL) return;

   TreeNode* cur = root;

   while (cur != NULL) {

      // idea is just have to connect the rightmost node in left subtree to cur->right
      if (cur->left != NULL) {

         TreeNode* prev = cur->left;
         while (prev->right) prev = prev->right;

         prev->right = cur->right;
         cur->right = cur->left;
         cur->left = NULL;
      }
      cur = cur->right; // go to next node in linked list

   }


}
