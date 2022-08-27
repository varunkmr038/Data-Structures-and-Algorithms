
class NodeInfo {
public:
  bool isBst;
  int size;
  int minValue;
  int maxValue;
};

NodeInfo solve(TreeNode<int>* root, int& ans) {

  NodeInfo val;
  if (root == NULL) {
    val.isBst = true;
    val.size = 0;
    val.minValue = INT_MAX;
    val.maxValue = INT_MIN;

    return val;
  }

  NodeInfo leftSub = solve(root->left, ans);
  NodeInfo rightSub = solve(root->right, ans);

  if (leftSub.isBst == 0 or rightSub.isBst == 0 or root->data < leftSub.maxValue or root->data > rightSub.minValue) {
    // iam not bst

    val.isBst = false;
    val.size = leftSub.size + rightSub.size + 1;
    return val;
  }

  // iam bst
  val.size = leftSub.size + rightSub.size + 1;
  ans = max(ans, val.size); // update ans

  val.isBst = true;

  if (root->left == NULL) val.minValue = root->data;
  else val.minValue = leftSub.minValue;

  if (root->right == NULL) val.maxValue = root->data;
  else val.maxValue = rightSub.maxValue;

  return val;
  |
}

//  Time: O(N)  Space: O(N)
int largestBST(TreeNode<int>* root)
{
  int ans = 0;

  solve(root, ans);

  return ans;
}
