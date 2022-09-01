// Time: O(N) Space: O(N)
TreeNode* sortedArrayToBST(vector<int>& nums) {

  int n = nums.size();

  int start = 0, end = n - 1;

  return solve(nums, start, end);

}

TreeNode* solve(vector<int>& nums, int start, int end) {

  if (start > end) return NULL;

  int mid = (start + end) / 2;

  TreeNode* root = new TreeNode(nums[mid]);

  root->left = solve(nums, start, mid - 1);
  root->right = solve(nums, mid + 1, end);

  return root;

}