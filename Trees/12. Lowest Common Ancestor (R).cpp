
bool generatePath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {

	if (root == NULL) return false;

	path.push_back(root);

	if (root == p) return true;

	// if left brings true then i will not go in right bcoz  i have found the path in left and return true
	if (generatePath(root->left, p, path) or  generatePath(root->right, p, path))
		return true;

	// path is not in left and right
	// so remove current
	path.pop_back();

	return false;
}


//  Time: O(2*N)  Space: O(2*N) Brute Force Storing the paths to p and q and then finding the common
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	vector<TreeNode*> path1, path2;

	generatePath(root, p, path1);
	generatePath(root, q, path2);

	int i = 0, j = 0;

	TreeNode* ans = root;
	while (i < path1.size() and j < path2.size()) {
		if (path1[i] != path2[j]) break; // split ho gye paths so previous node will be the lca

		ans = path1[i]; // common node
		i++; j++;
	}
	return ans;
}

// ---------------------------------------------------------------------------------------

// so we have to improve

//  Time: O(N)  Space: O(N) Using DFS Recursive
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	if (root == NULL) return NULL;

	if (root == p or root == q) return root;

	TreeNode* leftSub = lowestCommonAncestor(root->left, p, q);
	TreeNode* rightSub = lowestCommonAncestor(root->right, p, q);

	// iam the ancestor
	if (leftSub != NULL and rightSub != NULL) return root;
	else if (leftSub != NULL and rightSub == NULL) return leftSub; // mere left me ancestor mil gya
	else return rightSub;
}

// ---------------------------------------------------------------------------------------

