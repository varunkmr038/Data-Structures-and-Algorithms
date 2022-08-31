// Time: O(N!) Space: O(N^2)
vector<vector<string>> solveNQueens(int n) {

	vector<vector<string>> ans;
	vector<string> cur(n);
	string s(n, '.');
	for (int i = 0; i < n; i++) {
		cur[i] = s;
	}

	solve(n, 0, cur, ans);
	return ans;
}

bool isSafe(vector<string> cur, int row, int col, int n) {

	for (int i = row; i >= 0; i--) {
		if (cur[i][col] == 'Q') return 0;
	}

	int i = row, j = col;

	while (i >= 0 and j >= 0) {
		if (cur[i][j] == 'Q') return 0;
		i--; j--;
	}

	i = row; j = col;
	while (i >= 0 and j < n) {
		if (cur[i][j] == 'Q')return 0;
		i--; j++;
	}
	return 1;
}


void solve(int n, int row, vector<string> cur, vector<vector<string>>& ans) {


	if (row == n) {
		ans.push_back(cur);
		return;
	}

	for (int col = 0; col < n; col++) {

		if (isSafe(cur, row, col, n)) {

			cur[row][col] = 'Q';

			solve(n, row + 1, cur, ans);

			cur[row][col] = '.';
		}
	}
}

// ----------------------------------------------------------------------------------


vector<int> checkColumn(18, 0);
vector<int> leftDiagonal(18, 0);
vector<int> rightDiagonal(18, 0);

class Solution {
public:


// Time: O(N!) Space: O(N^2)  time optimised
	vector<vector<string>> solveNQueens(int n) {

		vector<vector<string>> ans;
		vector<string> cur(n);
		string s(n, '.');
		unordered_map<int, bool> mp;
		for (int i = 0; i < n; i++) {
			cur[i] = s;
		}

		solve(n, 0, cur, ans);
		return ans;
	}

	bool isSafe(vector<string> cur, int row, int col, int n) {

		if (checkColumn[col] or leftDiagonal[col + row] or rightDiagonal[n - 1 + col - row])
			return 0;

		return 1;

	}


	void solve(int n, int row, vector<string> cur, vector<vector<string>>& ans) {

		if (row == n) {
			ans.push_back(cur);
			return;
		}

		for (int col = 0; col < n; col++) {

			if (isSafe(cur, row, col, n)) {

				cur[row][col] = 'Q';

				checkColumn[col] = 1;
				leftDiagonal[col + row] = 1;
				rightDiagonal[col + n - row - 1] = 1;


				solve(n, row + 1, cur, ans);

				cur[row][col] = '.';


				checkColumn[col] = 0;
				leftDiagonal[col + row] = 0;
				rightDiagonal[col + n - row - 1] = 0;

			}
		}
	}
};