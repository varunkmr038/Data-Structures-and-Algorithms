//  Time: O(N)  Space: O(N) Recursion
int diameterOfBinaryTree(TreeNode* root) {
	int ans = 0;

	solve(root, ans);

	return ans;
}

int solve(TreeNode* root, int& ans) {

	if (root == NULL) return -1;

	int leftHeight = solve(root->left, ans);
	int rightHeight = solve(root->right, ans);

	int diameterPassingthroughMe = 2 + leftHeight + rightHeight;

	ans = max(ans, diameterPassingthroughMe);
	return 1 + max(leftHeight, rightHeight);
}