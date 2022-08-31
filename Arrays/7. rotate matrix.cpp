//  Time: O(N^2) Space: O(N^2) Brute Force Extra space
void rotate(vector<vector<int>>& matrix) {

  int n = matrix.size();

  vector<vector<int>> temp(n, vector<int>(n));

  for (int col = 0; col < n; col++) { // iterate col wise
    for (int row = 0; row < n; row++) {
      temp[col][n - row - 1] = matrix[ row][col];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = temp[i][j];
    }
  }

}


// -------------------------------------------------------------

//  Time: O(N^2) Space: O(1) Inplace rotation
void rotate(vector<vector<int>>& matrix) {

  int n = matrix.size();

  for (int row = 0; row < n; row++) {
    for (int col = row + 1; col < n; col++) {
      swap(matrix[row][col], matrix[col][row]);
    }

    reverse(matrix[row].begin(), matrix[row].end());

  }

}