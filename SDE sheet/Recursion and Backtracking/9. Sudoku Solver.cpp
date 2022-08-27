//  Time: O(9^9*9) Space: O(9^2)
void solveSudoku(vector<vector<char>>& board) {

	solve(board, 0, 0);

}

bool canPlace(vector<vector<char>>& board, int num, int row, int col) {

	if (board[row][col] != '.') return 0;

	for (int i = 0; i < 9; i++) {

		if (board[i][col] == num + 48) return 0;
		if (board[row][i] == num + 48) return 0;

	}

	int rootn = sqrt(9);

	int startRow = (row / rootn) * rootn;
	int startCol = (col / rootn) * rootn;

	for (int i = startRow; i < startRow + rootn; i++) {

		for (int j = startCol; j < startCol + rootn; j++) {
			if (board[i][j] == num + 48) return 0;
		}
	}

	return 1;
}

bool solve(vector<vector<char>>& board, int i, int j) {

	if (i == 9) return true;
	if (j == 9) return solve(board, i + 1, 0);
	if (board[i][j] != '.') return solve(board, i, j + 1);

	for (int num = 1; num <= 9; num++) {

		if (canPlace(board, num, i, j)) {

			board[i][j] = num + 48;
			bool success = solve(board, i, j + 1);

			if (success) return true;

			board[i][j] = '.';
		}
	}

	return false;


}