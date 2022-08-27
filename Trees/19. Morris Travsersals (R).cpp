


//  Time: O(N) Space: O(1) Morris Inorder Traversal without changing the original tree
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;

	if (root == NULL) return ans;

	TreeNode* cur = root;

	while (cur != NULL) {

		if (cur->left == NULL) {
			ans.push_back(cur->val);
			cur = cur->right;
		}

		else {
			// check krna hai ki left subtree visit kr chuka hu yaa nhi
			TreeNode* prev = cur->left;

			while (prev->right != NULL and prev->right != cur) {
				prev = prev->right;
			}

			if (prev->right == NULL) {
				// thread bnao cur pe
				// left subtree abhi unvisited
				prev->right = cur;
				cur = cur->left;
			}

			else {
				// if there is already a thread
				// remove the thread
				prev->right = NULL;
				ans.push_back(cur->val);
				cur = cur->right;
			}
		}


	}

	return ans;
}

//--------------------------------------------------------------------------------




//  Time: O(N) Space: O(1) Morris Preorder Traversal without changing the original tree
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ans;

	if (root == NULL) return ans;

	TreeNode* cur = root;

	while (cur != NULL) {

		if (cur->left == NULL) {
			ans.push_back(cur->val);
			cur = cur->right;
		}

		else {
			// check krna hai ki left subtree visit kr chuka hu yaa nhi
			TreeNode* prev = cur->left;

			while (prev->right != NULL and prev->right != cur) {
				prev = prev->right;
			}

			if (prev->right == NULL) {
				// thread bnao cur pe
				// left subtree abhi unvisited
				prev->right = cur;
				ans.push_back(cur->val); //  pehli baar mark karte time push krna
				cur = cur->left;
			}

			else {
				// if there is already a thread
				// remove the thread
				prev->right = NULL;
				cur = cur->right;
			}
		}


	}

	return ans;
}