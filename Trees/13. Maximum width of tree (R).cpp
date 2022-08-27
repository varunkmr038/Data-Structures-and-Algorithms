

//  Time: O(N)  Space: O(2*N) BFS
int widthOfBinaryTree(TreeNode* root) {

	int ans = 1;
	queue<pair<TreeNode*, long long int>> q; // {node,index}
	q.push({root, 1});

	// you have to index each node
	// parent - i
	// left child- (i-mn)*2 +1    , right - (i-mn)*2 + 2
	while (!q.empty()) {

		int len = q.size();

		int firstIndex = 0, lastIndex = 0;

		int mn = q.front().second;

		for (int i = 0; i < len; i++) {
			auto cur = q.front();
			q.pop();

			// agar mn ko har baar 1 leta to overflow ho jayega

			if (cur.first->left) q.push({cur.first->left, (cur.second - mn) * 2 + 1}); // 2*i
			if (cur.first->right) q.push({cur.first->right, (cur.second - mn) * 2 + 2 }); //2*i+1


			if (i == 0) firstIndex = cur.second;
			if (i == len - 1) lastIndex = cur.second;
		}

		ans = max(ans, lastIndex - firstIndex + 1);
	}
	return ans;
}


// ----------------------------------------------------------------------------------------


// without indexing
// here iam treating it as complete binary tree
// null ke bhi childrens null push kre queue me
// but this soln will give tle on leetcode as for 10^3 levels

//  Time: O(N)  Space: O(N) BFS using deque
int widthOfBinaryTree(TreeNode* root) {

	int ans = 1;
	deque<TreeNode*> dq;
	dq.push_back(root);       // N N N 5 6 N N 6 N N len=5

	while (!dq.empty()) {

		while (!dq.empty() and  dq.back() == NULL) dq.pop_back();// peeche se null hatana
		while (!dq.empty() and  dq.front() == NULL) dq.pop_front();// aage se null hatana

		int len = dq.size();
		ans = max(ans, len);

		for (int i = 0; i < len; i++) {
			auto cur = dq.front();
			dq.pop_front();

			if (cur ==  NULL) {
				dq.push_back(NULL);
				dq.push_back(NULL);
			}
			else {
				dq.push_back(cur->left);
				dq.push_back(cur->right);
			}
		}
	}
	return ans;
}