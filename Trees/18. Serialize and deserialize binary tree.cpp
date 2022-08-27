

// 1 2 N N -15 4 N N 5 N N

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
// preorder

	string ans = "";

	if (root == NULL) {
		ans += "N ";
		return ans;
	}

	ans += to_string(root->val);
	ans += " ";

	ans += serialize(root->left);
	ans += serialize(root->right);

	return ans;
}

TreeNode* solve(string& data, int& idx) {
	int n = data.size();

	if (data[idx] == 'N') {
		idx += 2;
		return NULL;
	}

	/// jb tk space nhi ata
	string cur = "";
	while (data[idx] != ' ')
		cur += data[idx++];

	idx++;

	int val = stoi(cur);

	TreeNode * root = new TreeNode(val);

	root->left = solve(data, idx);
	root->right = solve(data, idx);

	return root;
}

//  Time : O(N) Space: O(N) Using preorder recusrive
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {


	if (data.size() == 0) return NULL;
	int idx = 0; // global idx for string data
	return solve(data, idx);
}

// ----------------------------------------------------------------------------------------


// Encodes a tree to a single string.
string serialize(TreeNode* root) {
// using bfs level order travsersal

	string ans = "";

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		TreeNode* cur = q.front();
		q.pop();

		if (cur == NULL) ans += "N ";
		else {

			ans += to_string(cur->val);
			ans += " ";

			q.push(cur->left);
			q.push(cur->right);
		}
	}
	return ans;
}



int extractNumber(string& data, int& idx) {
	string cur = "";
	while (data[idx] != ' ')
		cur += data[idx++];
	idx++;
	int val = stoi(cur);

	return val;
}

//  Time : O(N) Space: O(N) Using BFS level order
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {

	if (data.size() == 0 or data[0] == 'N') return NULL;

	queue <TreeNode*> q;
	int idx = 0;

	int val = extractNumber(data, idx);
	TreeNode* root = new TreeNode(val);
	q.push(root);

	while (!q.empty()) {

		TreeNode* curNode = q.front();
		q.pop();

		if (curNode == NULL) continue;

		// connect the left children
		if (data[idx] == 'N') idx += 2;
		else {
			int curVal = extractNumber(data, idx);
			curNode->left = new TreeNode(curVal);
			q.push(curNode->left);
		}

		// connect the right child
		if (data[idx] == 'N') idx += 2;
		else {
			int curVal = extractNumber(data, idx);
			curNode->right = new TreeNode(curVal);
			q.push(curNode->right);
		}
	}

	return root;
}
