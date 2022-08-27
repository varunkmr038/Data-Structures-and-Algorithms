
void incrementSubtree(BinaryTreeNode<int>* root, int diff) {

	if (root == NULL)	return ;

	root->data = root->data + diff;

	if (root->left)
		incrementSubtree(root->left, diff);
	else
		incrementSubtree(root->right, diff);
}


//  Time: O(N^2)  Space: O(H) DFS Recursive neeche se upar aate hue condition check krna
void changeTree(BinaryTreeNode < int > * root) {

	if (root == NULL) return;
	if (root->left == NULL and root->right == NULL) return ; //leaf node

	changeTree(root->left);
	changeTree(root->right);

	// tree neeche se kaam krna hai // bottom se up ana hai
	int leftChildVal = root->left ? root->left->data : 0;
	int rightChildVal = root->right ? root->right->data : 0;

	if (root->data <= (leftChildVal + rightChildVal)) root->data = leftChildVal + rightChildVal;

	// neeche subtree me increment krna hai diff
	else {
		int diff = root->data - (leftChildVal + rightChildVal);

		if (root->left)
			incrementSubtree(root->left, diff);
		else
			incrementSubtree(root->right, diff);
	}
}

//-------------------------------------------------------------------------------------------

//  Time: O(N) Space: O(N) DFS
void changeTree(BinaryTreeNode < int > * root) {

	if (root == NULL) return ;

	int leftChildVal = root->left ? root->left->data : 0;
	int rightChildVal = root->right ? root->right->data : 0;

	// neeche jaate samay child value of max possible bna ke jao
	// child values ko increase krte hue jao kyuki cur node value ko reduce krna allowed nhi hai
	if (root->data > (leftChildVal + rightChildVal)) {

		// this assures that whatever update in the subtree cur node will get val <= child and then i will keep cur node val = child while going back
		if (root->left) root->left->data = root->data; // if left exists update it with my val
		if (root->right) root->right->data = root->data; // if right exists update it with my val
	}

	changeTree(root->left);
	changeTree(root->right);

	// or wapas jaate samay shi values allot sum up  krdo
	int curValue = 0;
	if (root->left) curValue += root->left->data;
	if (root->right) curValue += root->right->data;

	if (root->left or root->right) root->data = curValue; // if iam not leaf value
}