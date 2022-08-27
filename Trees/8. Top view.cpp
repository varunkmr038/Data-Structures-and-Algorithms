
void solve(TreeNode<int>* root, map<int, int>& mp) {

	if (root == NULL) return;

	queue<pair<TreeNode<int>*, int>> q;

	q.push({root, 0});

	while (!q.empty()) {

		auto cur = q.front();
		q.pop();

		int hD = cur.second;

		// iam the first one so iam top view
		if (!mp.count(hD)) mp[hD] = cur.first->val;

		if (cur.first->left) q.push({cur.first->left, hD - 1});
		if (cur.first->right) q.push({cur.first->right, hD + 1});
	}
}

//  Time: O(N*Logn)  Space: O(N) Using bfs and map
vector<int> getTopView(TreeNode<int> *root) {

	vector<int> ans;
	if (root == NULL) return ans;

	map<int, int> mp;

	solve(root, mp);

	for (auto& x : mp) {
		ans.push_back(x.second);
	}

	return ans;
}

// ---------------------------------------------------------------------------------------
