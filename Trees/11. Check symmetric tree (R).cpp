
bool solve(TreeNode* root1, TreeNode* root2) {

	if (root1 == NULL or root2 == NULL) {
		return root1 == root2;
	}

	if (root1->val != root2->val) return false;

	bool sub1 = solve(root1->left, root2->right); // ek left me jayega or ek right me
	bool sub2 = solve(root1->right, root2->left);

	return sub1 and sub2;
}



//  Time: O(N)  Space: O(N) Using DFS
bool isSymmetric(TreeNode* root) {
	// for every node check left subtree = right subtree
	return solve(root, root);
}
// ---------------------------------------------------------------------------------------

// O(N)
bool isPalindrome(vector<int>& a) {

	int i = 0, j = a.size() - 1;
	while (i < j) {
		if (a[i] != a[j]) return false;
		i++; j--;
	}
	return true;
}


//  Time: O(2*N)  Space: O(2*N) Using BFS
bool isSymmetric(TreeNode* root) {
	// for every node check left subtree = right subtree
	// generating each level and checking palindrome

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		int len = q.size();
		vector<int> currentLevel;

		// im gonna also consider null also
		// bcoz for we also need null orientations to check palindrome of level
		while (len--) {

			TreeNode* cur = q.front();
			q.pop();

			if (cur == NULL) {
				currentLevel.push_back(INT_MIN); // INT_MIN = null
			}
			else {
				currentLevel.push_back(cur->val);

				q.push(cur->left);
				q.push(cur->right);
			}
		}

		// current level is not palindrom so it is not symmetric
		if (!isPalindrome(currentLevel)) return false;
	}

	return true;
}

//--------------------------------------------------------------------------------------------------------



//  Time: O(N)  Space: O(2*N) Using BFS and 2 queues
bool isSymmetric(TreeNode* root) {

	queue<TreeNode*> q1, q2;
	q1.push(root->left);
	q2.push(root->right);

	while (!q1.empty() and !q2.empty()) {

		TreeNode* cur1 = q1.front();
		q1.pop();

		TreeNode* cur2 = q2.front();
		q2.pop();

		if (!cur1 and !cur2) continue;
		if (!cur1 and cur2) return false;
		if (cur1 and !cur2) return false;

		if (cur1->val != cur2->val) return false;

		q1.push(cur1->left);
		q1.push(cur1->right);
		q2.push(cur2->right);
		q2.push(cur2->left);

	}

	return true;
}


