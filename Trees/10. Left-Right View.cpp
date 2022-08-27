
void solve(TreeNode* root, int level, map<int, int>& mp) {

	if (root == NULL) return;

	if (!mp.count(level)) mp[level] = root->val;

	solve(root->right, level + 1, mp);
	solve(root->left, level + 1, mp);
}

//  Time: O(N*Logn)  Space: O(N) Using DFS and map
vector<int> rightSideView(TreeNode *root) {

	vector<int> ans;
	if (root == NULL) return ans;

	map<int, int> mp;

	solve(root, 0, mp);

	for (auto& x : mp) {
		ans.push_back(x.second);
	}

	return ans;
}

// ---------------------------------------------------------------------------------------


// har level pe last banda right view hai
void solve(TreeNode* root, map<int, int>& mp) {

	if (root == NULL) return;

	queue<pair<TreeNode*, int>> q;

	q.push({root, 0});

	while (!q.empty()) {
		int len = q.size();

		for (int i = 0; i < len; i++) {

			auto cur = q.front();
			q.pop();


			int vD = cur.second;

			if (i == len - 1)
				mp[vD] = cur.first->data;

			if (cur.first->left) q.push({cur.first->left, vD + 1});
			if (cur.first->right) q.push({cur.first->right, vD + 1});
		}
	}
}

//  Time: O(N*Logn)  Space: O(N) Using bfs and map
vector<int> rightSideView(TreeNode *root) {

	vector<int> ans;
	if (root == NULL) return ans;

	map<int, int> mp;

	solve(root, mp);

	for (auto& x : mp) {
		ans.push_back(x.second);
	}

	return ans;
}

// -------------------------------------------------------------------------------------------------


void solve(TreeNode* root, int level, int& firstTime, vector<int>& ans) {

	if (root == NULL) return;

	if (level == firstTime) {
		ans.push_back(root->val);
		firstTime++;
	}

	solve(root->right, level + 1, firstTime, ans);
	solve(root->left, level + 1, firstTime, ans);
}

//  Time: O(N*Logn)  Space: O(h) Using DFS
vector<int> rightSideView(TreeNode *root) {

	vector<int> ans;
	if (root == NULL) return ans;

	int firstTime = 0;
	solve(root, 0, firstTime, ans);
	return ans;
}

// ---------------------------------------------------------------------------------------