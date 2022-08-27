
// here iam gonna take 0 based height not -1
int leftHeight(TreeNode* root) {
	int ans = 0;

	while (root != NULL) {
		root = root->left;
		ans++;
	}

	return ans;
}

int rightHeight(TreeNode* root) {
	int ans = 0;
	while (root != NULL) {
		root = root->right;
		ans++;
	}
	return ans;
}

// Time: O(Logn) Space: O(Logn)
int countNodes(TreeNode* root) {

	if (root == NULL) return 0;

	int lh = leftHeight(root);
	int rh = rightHeight(root);

	//this subtree is  complete binary tree so total nodes will be 2^h-1
	if (lh == rh) return ((1 << lh) - 1);

	return (1 + countNodes(root->left) + countNodes(root->right));
}