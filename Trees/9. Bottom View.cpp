
void solve(BinaryTreeNode<int>* root, map<int, int>& mp) {

	if (root == NULL) return;

	queue<pair<BinaryTreeNode<int>*, int>> q;

	q.push({root, 0});

	while (!q.empty()) {

		auto cur = q.front();
		q.pop();

		int hD = cur.second;

		// iam the last one so iam bottom view
		mp[hD] = cur.first->data;

		if (cur.first->left) q.push({cur.first->left, hD - 1});
		if (cur.first->right) q.push({cur.first->right, hD + 1});
	}
}

//  Time: O(N*Logn)  Space: O(N) Using bfs and map
vector<int> bottomView(BinaryTreeNode<int> *root) {

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
