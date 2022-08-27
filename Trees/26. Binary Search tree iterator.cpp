
// Time: O(N) Space: O(N) Brute force storing the inorder
class BSTIterator {

  vector<int> inorder;
  int idx;

public:
  BSTIterator(TreeNode* root) {
    idx = -1;
    inorderTraversal(root);
  }

  // O(1) O(N)
  int next() {
    idx++;
    return inorder[idx];
  }

// O(1) O(N)
  bool hasNext() {
    return (idx + 1) < inorder.size();
  }


};

// ------------------------------------------------------------------------------

class BSTIterator {

  stack<TreeNode*> st;

public:
  BSTIterator(TreeNode* root) {
    leftTraversal(root);
  }

  // O(1) O(H)
  int next() {
    TreeNode* cur = st.top();
    st.pop();

    leftTraversal(cur->right);

    return cur->val;
  }

// O(1) O(H)
  bool hasNext() {
    return st.size() > 0;
  }

  void leftTraversal(TreeNode* root) {
    while (root != NULL) {
      st.push(root);
      root = root->left;
    }
  }

};

