
// boundary traversal -
// 1. Left boundary without leaf - har level pe leftmost node
// 2. Bottom boundary  - saari leaf nodes
// 3. Right Boundary in reverse without leaf - har level pe rightmost node

bool isLeaf(TreeNode<int>* root) {
	return (root->left == NULL and root->right == NULL);
}

void leftBoundary(TreeNode<int>* root, vector<int>& ans) {

	TreeNode<int>* cur = root->left;
	while (cur) {
		if (isLeaf(cur)) break;
		ans.push_back(cur->data);
		if (cur->left) cur = cur->left; // prioritize left over right
		else cur = cur->right;
	}
}

void rightBoundary(TreeNode<int>* root, vector<int>& ans) {

	TreeNode<int>* cur = root->right;
	vector<int> temp;

	while (cur) {
		if (isLeaf(cur)) break;
		temp.push_back(cur->data);
		if (cur->right) cur = cur->right; // prioritize left over right
		else cur = cur->left;
	}

	for (int i = temp.size() - 1; i >= 0; i--) ans.push_back(temp[i]);
}

void bottomBoundary(TreeNode<int>* root, vector<int>& ans) {

	if (root == NULL) return ;

	if (isLeaf(root)) ans.push_back(root->data);

	bottomBoundary(root->left, ans);
	bottomBoundary(root->right, ans);
}


//  Time: O(N)  Space: O(N)
vector<int> traverseBoundary(TreeNode<int>* root) {
	vector<int> ans;
	if (root == NULL) return ans;

	ans.push_back(root->data);
	if (isLeaf(root)) return ans;

	leftBoundary(root, ans);
	bottomBoundary(root, ans);
	rightBoundary(root, ans);

	return ans;
}