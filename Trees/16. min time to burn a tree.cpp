
//  O(N)
void markParents(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent, BinaryTreeNode<int>*& startNode, int start) {

	if (root == NULL) return ;

	if (root->data == start) startNode = root;

	if (root->left) parent[root->left] = root;
	if (root->right) parent[root->right] = root;

	markParents(root->left, parent, startNode, start);
	markParents(root->right, parent, startNode, start);
}


int bfs(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent) {

	int ans = 0;

	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	unordered_map<BinaryTreeNode<int>*, int> vis;

	while (!q.empty()) {

		int len = q.size();

		while (len--) {
			auto cur = q.front();
			q.pop();

			vis[cur] = 1;

			if ( parent[cur] != NULL and !vis.count(parent[cur])) q.push(parent[cur]);
			if ( cur->left != NULL and !vis.count(cur->left)) q.push(cur->left);
			if ( cur->right != NULL and !vis.count(cur->right)) q.push(cur->right);
		}
		ans++; // inc the seconds
	}
	return ans - 1;
}


//  Time: O(N)  Space: O(N) BFS on start node
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
	unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;

	BinaryTreeNode<int>* startNode;
	markParents(root, parent, startNode, start);
	parent[root] = NULL; // main root ka no parent


	return bfs(startNode, parent);

}