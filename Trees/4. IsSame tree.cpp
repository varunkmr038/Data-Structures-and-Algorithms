

//  Time: O(N)  Space: O(N) Recursion
bool isSameTree(TreeNode* p, TreeNode* q) {

	if (p == NULL or q == NULL) return p == q;

	if (p->val != q->val) return false;
	bool left = isSameTree(p->left, q->left);
	bool right = isSameTree(p->right, q->right);

	return left and right;
}