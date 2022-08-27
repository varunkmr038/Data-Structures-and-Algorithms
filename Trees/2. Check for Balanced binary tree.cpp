

//  Time: O(N)  Space: O(N)
bool isBalanced(TreeNode* root) {
	return solve(root) != -1;  // if -1 then tree is not balanced
}

int solve(TreeNode* root) {

	if (root == NULL) return 0;

	int leftHeight = solve(root->left);
	int rightHeight = solve(root->right);

	if (leftHeight == -1 or rightHeight == -1) return -1;

	if (abs(leftHeight - rightHeight) > 1) return -1;

	return 1 + max(leftHeight, rightHeight);
}