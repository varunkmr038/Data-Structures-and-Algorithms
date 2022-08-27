

void searchAtDistanceK(TreeNode* root, int k, vector<int>& ans) {

	if (root == NULL) return ;

	if (k == 0) {
		ans.push_back(root->val);
		return ;
	}

	searchAtDistanceK(root->left, k - 1, ans);
	searchAtDistanceK(root->right, k - 1, ans);

}


int solve(TreeNode* root, TreeNode* target, int k, vector<int>& ans) {

	if (root == NULL) return -1; // -1 indicates that target node is not found yet

	if (root == target) {
		// you get the target node
		// now you gonna search in your subtree k distance nodes
		searchAtDistanceK(root, k, ans);
		return 0;
	}

	// iam gonna search left and right for target node
	int searchLeft = solve(root->left, target, k, ans);
	int searchRight = solve(root->right, target, k, ans);

	if (searchLeft == -1 and searchRight == -1) return -1; // target not found in left and right

	// ab target node yaa to left me mili hogi ya right me dono jagah nhi mil skti
	int distToTarget = searchLeft != -1 ? searchLeft + 1 : searchRight + 1;

	// target found in left subtree
	if (searchLeft >= 0) {
		if (distToTarget > k) return distToTarget;
		else if (distToTarget == k) ans.push_back(root->val); // cur banda target ke upar k dist pe hau

		// go in right and search at distance  k-distToTarget
		else {
			searchAtDistanceK(root->right, k - distToTarget - 1, ans);
		}
	}

	// in right subtree
	else {

		if (distToTarget > k) return distToTarget;
		else if (distToTarget == k) ans.push_back(root->val);

		// go in left
		else {
			searchAtDistanceK(root->left, k - distToTarget - 1, ans);
		}
	}
	return distToTarget;
}


//  Time: O(N)  Space: O(N) DFS Recursive
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

	vector<int> ans;

	solve(root, target, k, ans);

	return ans;
}


// -----------------------------------------------------------------------------------------

//  O(N)
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {

	if (root == NULL) return ;

	if (root->left) parent[root->left] = root;
	if (root->right) parent[root->right] = root;

	markParents(root->left, parent);
	markParents(root->right, parent);
}

void dfs(TreeNode* root, int k, vector<int>& ans, unordered_map<TreeNode*, TreeNode*>& parent,	unordered_map<TreeNode*, int>& vis) {

	if (root == NULL) return;
	if (vis.count(root)) return; // if cur root visited

	if (k == 0) {
		ans.push_back(root->val);
		return;
	}

	vis[root] = 1;

	dfs(parent[root], k - 1, ans, parent, vis); // call for parent
	dfs(root->left, k - 1, ans, parent, vis);
	dfs(root->right, k - 1, ans, parent, vis);

}



//  Time: O(N)  Space: O(N) Making the tree graph by parent pointers and using dfs on target node
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

	vector<int> ans;
	unordered_map<TreeNode*, TreeNode*> parent;

	markParents(root, parent);
	parent[root] = NULL; // main root ka no parent

	unordered_map<TreeNode*, int> vis;
	dfs(target, k, ans, parent, vis);

	return ans;
}

// similarly we can do this with bfs also