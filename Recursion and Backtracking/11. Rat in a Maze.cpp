
void solve(vector<vector<int>>& m, int i, int j, int n, string& path, vector<string>& ans, vector<vector<int>>& vis) {

	if (i == n - 1 and j == n - 1) {
		ans.push_back(path);
		return ;
	}
	if (i<0 or j<0 or  i >= n or j >= n or m[i][j] == 0) return;
	if (vis[i][j] == 1) return;

	vis[i][j] = 1;

	path += "R";
	solve(m, i, j + 1, n, path, ans, vis);
	path.pop_back();

	path += "D";
	solve(m, i + 1, j, n, path, ans, vis);
	path.pop_back();

	path += "L";
	solve(m, i , j - 1, n, path, ans, vis);
	path.pop_back();

	path += "U";
	solve(m, i - 1, j, n, path, ans, vis);
	path.pop_back();

	vis[i][j] = 0;
}

// Time: O(2^M*N)  Space: O(M*N) Recursion and backtracking
vector<string> findPath(vector<vector<int>> &m, int n) {

	vector<string> ans;
	vector<vector<int>> vis(m, vector<int>(n, 0));

	string path = "";
	solve(m, 0, 0, n, path, ans, vis);

	return ans;
}