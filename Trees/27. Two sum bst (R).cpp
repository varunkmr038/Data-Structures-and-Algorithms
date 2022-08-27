

bool search(TreeNode* root, int value, TreeNode*& pairNode) {
  if (root == NULL) return false;
  if (root->val == value and root != pairNode) return true;
  return (search(root->left, value, pairNode) or search(root->right, value, pairNode));
}



bool solve(TreeNode*& root, TreeNode* cur, int k) {
//going to every node and checking whether its pair exists in the tree or not
  if (cur == NULL) return false;

  // considering the cur node in pair
  bool searchPairLeft = search(root, k - cur->val, cur);
  bool searchPairRight = search(root, k - cur->val, cur);

  if (searchPairLeft or searchPairRight) return true; // if cur value pair exists then i found ans
  // if not explore left and right subtree

  return (solve(root, cur->left, k) or solve(root, cur->right, k));
}

// Time: O(N^2) Space: O(N) Brute force
bool findTarget(TreeNode* root, int k) {
  return solve(root, root, k);
}

// ---------------------------------------------------------------------------------------



void markNodes(TreeNode* root, unordered_map<int, int>& mp) {
  if (root == NULL) return ;

  mp[root->val]++;
  markNodes(root->left, mp);
  markNodes(root->right, mp);
}



bool solve(TreeNode*& root, int k, unordered_map<int, int>& mp) {
//going to every node and checking whether its pair exists in the map or not
  if (root == NULL) return false;

  mp[root->val]--;

  // considering the cur node in pair
  if (mp[k - root->val] > 0) return true;

  mp[root->val]++;

  return (solve(root->left, k, mp) or solve(root->right, k, mp));
}

// Time: O(N) Space: O(2*N) Using map
bool findTarget(TreeNode* root, int k) {

  unordered_map<int, int> mp;

  markNodes(root, mp);

  return solve(root, k, mp);
}

// -----------------------------------------------------------------------

// using bst iterator concept

class BSTIterator {

  stack<TreeNode*> st;
  bool isForward; // forward = 1 means iterator from left to right

public:

  TreeNode* cur;

  BSTIterator(TreeNode* root, bool isForward) {
    this->isForward = isForward;
    cur = NULL;
    traversal(root);
  }

  // O(1) O(H)
  void next() {
    cur = st.top();
    st.pop();

    if (isForward)
      traversal(cur->right); // you need next bigger element
    else traversal(cur->left);
  }

  void traversal(TreeNode* root) {
    while (root != NULL) {
      st.push(root);

      if (isForward == true)
        root = root->left;
      else root = root->right;
    }
  }

};



// Time: O(N) Space: O(H) Using BST iterator Two pointers
bool findTarget(TreeNode* root, int k) {

  BSTIterator* leftIt = new BSTIterator(root, true);
  BSTIterator* rightIt = new BSTIterator(root, false);

  leftIt->next();
  rightIt->next();

  while (leftIt->cur != rightIt->cur) {

    int pairSum = leftIt->cur->val + rightIt->cur->val;

    if (pairSum == k) return true;
    else if (pairSum > k) rightIt->next();
    else leftIt->next();
  }

  return false;
}