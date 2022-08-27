
//  Time: O(N) Space: O(N) Iterative Preorder travsersal 1 stack
vector<int> preorderTraversal(TreeNode* root) {

   vector<int> ans;

   stack<TreeNode*> st;
   if (root == NULL) return ans;
   st.push(root);

   while (!st.empty()) {

      TreeNode* cur = st.top();
      st.pop();

      ans.push_back(cur->val);
      if (cur->right)st.push(cur->right);
      if (cur->left)st.push(cur->left);
   }

   return ans;
}

// ----------------------------------------------------------------------------------------


//  Time: O(N) Space: O(2*N) Iterative Inorder travsersal 1 stack and 1 hashmap
vector<int> inorderTraversal(TreeNode* root) {
   vector<int> ans;

   if (root == NULL) return ans;

   unordered_map<TreeNode*, int> mp;
   stack<TreeNode*> st;

   st.push(root);
   while (!st.empty()) {

      TreeNode* cur = st.top();

      // if cur left exists and you have not visited it then first visit this
      if (cur->left != NULL and  !mp.count(cur->left)) {
         st.push(cur->left);
         mp[cur->left]++;
      }

      // you gonna  add cur to ans and pop cur and then add cur right to stack
      else {
         ans.push_back(cur->val);
         st.pop();

         if (cur->right != NULL) st.push(cur->right);
      }
   }

   return ans;
}

// ----------------------------------------------------------------------------------------


//  Time: O(N) Space: O(N) Iterative Inorder travsersal 1 stack
vector<int> inorderTraversal(TreeNode* root) {
   vector<int> ans;

   if (root == NULL) return ans;

   stack<TreeNode*> st;

   TreeNode* cur = root;

   while (cur != NULL or  !st.empty()) {

      // go to extreme left
      while (cur != NULL) {
         st.push(cur);
         cur = cur->left;
      }

      // cant go further left so just print val and move cur to right
      cur = st.top();
      st.pop();
      ans.push_back(cur->val);

      cur = cur->right;
   }
   return ans;
}


// ----------------------------------------------------------------------------------------

//in this method answer is correct but traversal is not post order

//  Time: O(N) Space: O(N) Iterative Post order travsersal 1 stack
vector<int> postorderTraversal(TreeNode* root) {

   vector<int> ans;
   if (root == NULL) return ans;

   stack<TreeNode*> st;
   st.push(root);

   // idea is to compute customized preorder N R L
   // and reverse it so it became post L R N
   while (!st.empty()) {

      TreeNode* cur = st.top();
      st.pop();

      ans.push_back(cur->val);

      // prioritizing right over left
      if (cur->left != NULL) st.push(cur->left); // hence pushes left first
      if (cur->right != NULL) st.push(cur->right);

   }

   reverse(ans.begin(), ans.end());

   return ans;
}



// ----------------------------------------------------------------- -----------------------

// striver way real post order soln
// traversal is post order

//  Time: O(N) Space: O(N) Iterative Post order travsersal 1 stack
vector<int> postorderTraversal(TreeNode* root) {

   vector<int> ans;
   if (root == NULL) return ans;

   stack<TreeNode*> st;
   TreeNode* cur = root;

   while (cur != NULL or !st.empty()) {

      // cur node ka left travsere krte rho
      if (cur != NULL) {
         st.push(cur);
         cur = cur->left;
      }
      else {
         // stack ke top waali node ke L R traversal pure hue ya nhi

         TreeNode* temp = st.top()->right;
         if (temp == NULL) {
            // you are on leaf node

            temp = st.top();
            st.pop();
            ans.push_back(temp->val);

            // i have L R traversal for current stack top node
            while (!st.empty() and st.top()->right == temp) { // upar ki taraf jaana
               temp = st.top();
               st.pop();
               ans.push_back(temp->val);
            }
         }
         else cur = temp;  // taaki hum is node ka right travserse kr ske
      }


   }

   return ans;
}


// ----------------------------------------------------------------------------------------


// 1 -> preorder  2-> inorder  3 -> postorder

//  Time: O(N) Space: O(N) Iterative
void allTraversals(TreeNode* root) {

   vector<int> pre, in, post;

   stack<pair<TreeNode*, int>> st;
   st.push({root, 1});

   while (!st.empty()) {

      auto cur = st.top();
      st.pop();

      // preorder
      if (cur.second == 1) {

         pre.push_back(cur.first->val);
         cur.second++;
         st.push(cur);

         if (cur.first->left != NULL) st.push(cur.first->left);
      }
      // in
      else if (cur.second == 2) {

         in.push_back(cur.first->val);
         cur.second++;
         st.push(cur);

         if (cur.first->right != NULL) st.push(cur.first->right);
      }
      // post
      else {
         post.push_back(cur.first->val);
      }
   }

}
