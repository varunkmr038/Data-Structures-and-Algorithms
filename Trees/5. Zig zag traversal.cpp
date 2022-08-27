

//  Time: O(N)  Space: O(N) Using BFS level by level
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

	vector<vector<int>> ans;
	if (root == NULL) return ans;

	queue<TreeNode*> q;
	q.push(root);

	bool leftToRight = 1;

	while (!q.empty()) {

		int len = q.size();

		vector<int> v;
		for (int i = 0; i < len; i++) {

			TreeNode* cur = q.front();
			q.pop();

			v.push_back(cur->val);

			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}

		if (!leftToRight) reverse(v.begin(), v.end());

		leftToRight = !leftToRight;  // change the dirn for next level
		ans.push_back(v);
	}
	return ans;
}