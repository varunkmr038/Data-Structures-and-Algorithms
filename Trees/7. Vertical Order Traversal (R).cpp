
// you are gonna mark nodes on horizontal scale
//	-2 -1 0 1 2 3
// we can also do it using dfs

class NodeInfo {
public:
	TreeNode* root;
	int hD;
	int vD;

	NodeInfo(TreeNode* root, int hD, int vD) {
		this->root = root;
		this->hD = hD;
		this->vD = vD;
	}
};

void solve(TreeNode* root, map<int, map<int, multiset<int>> >& mp) {

	// pair {root , hD, vD}
	queue <NodeInfo*> q;

	q.push(new NodeInfo(root, 0, 0));

	while (!q.empty()) {

		int len = q.size();

		while (len--) {
			auto cur = q.front();
			q.pop();

			TreeNode* curNode = cur->root;
			int hD = cur->hD;
			int vD = cur->vD;

			// save the value in map
			mp[hD][vD].insert(curNode->val);

			if (curNode->left) q.push(new NodeInfo(curNode->left, hD - 1, vD + 1));
			if (curNode->right)  q.push(new NodeInfo(curNode->right, hD + 1, vD + 1));
		}
	}
}

//  Time: O(N*Logn)  Space: O(N) Using bfs on triplet of root,horizontal and vertical
vector<vector<int>> verticalTraversal(TreeNode* root) {

	// horizontal dist -->  vertical dist --> multi nodes at same place
	map<int, map<int, multiset<int>>> mp;
	vector<vector<int>> ans;

	if (root == NULL) return ans;

	solve(root, mp);

	for (auto& x : mp) { // horizontal dist

		vector<int> v;
		for (auto& y : x.second) { // iterating over level
			// upar se neeche aa rhe hai ek line me
			for (auto& val : y.second) v.push_back(val); // for multinodes at same place
		}
		ans.push_back(v);
	}

	return ans;
}

// ---------------------------------------------------------------------------------------


void solve(TreeNode* root, int hD, int vD, map<int, map<int, multiset<int>> >& mp) {

	if (root == NULL) return ;

	mp[hD][vD].insert(root->val);

	solve(root->left, hD - 1, vD + 1, mp);
	solve(root->right, hD + 1, vD + 1, mp);
}

//  Time: O(N*Logn)  Space: O(N) Using dfs
vector<vector<int>> verticalTraversal(TreeNode* root) {

	// horizontal dist -->  vertical dist --> multi nodes at same place
	map<int, map<int, multiset<int>>> mp;
	vector<vector<int>> ans;

	if (root == NULL) return ans;

	solve(root, 0, 0, mp);

	for (auto& x : mp) { // horizontal dist

		vector<int> v;
		for (auto& y : x.second) { // iterating over level
			// upar se neeche aa rhe hai ek line me
			for (auto& val : y.second) v.push_back(val); // for multinodes at same place
		}
		ans.push_back(v);
	}

	return ans;
}