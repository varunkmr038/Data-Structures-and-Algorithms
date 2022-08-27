

//  Time: O(N^3) Space: O(N^2) Brute Force
void setZeroes(vector<vector<int>>& matrix) {

  int matrix = matrix.size(), m = matrix[0].size();

  //  Creates new matrix for modifications
  vector<vector<int>> v(n, vector<int> (m, 1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      // O(M+N)
      if (matrix[i][j] == 0) {

        for (int k = 0; k < m; k++) v[i][k] = 0;
        for (int k = 0; k < n; k++) v[k][j] = 0;

      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) matrix[i][j] = v[i][j];
  }
}

//- --------------------------------------------------------------------------------------------


//  Time: O(M*N) Space: O(M+N) Taking the rows and cols vector
void setZeroes(vector<vector<int>>& matrix) {

  int n = matrix.size(), m = matrix[0].size();

  // if rows[i]=0 then make the ith row zero
  vector<bool> rows(n, 1);
  vector<bool> cols(m, 1); // same with col


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) {
        rows[i] = 0; // make the current row and col zero
        cols[j] = 0;
      }
    }
  }

  //  For marking rows as zero
  for (int i = 0; i < n; i++) {
    if (rows[i] == 0) {
      for (int j = 0; j < m; j++) matrix[i][j] = 0;
    }
  }

  //  For cols
  for (int i = 0; i < m; i++) {
    if (cols[i] == 0) {
      for (int j = 0; j < n; j++) matrix[j][i] = 0;
    }
  }
}

// ----------------------------------------------------------------------------------------

//  Time: O(2*M*N) Space: O(1) using the first row and col as flags for marking zero
void setZeroes(vector<vector<int>>& matrix) {

  int n = matrix.size(), m = matrix[0].size();


  bool firstRow = 1, firstCol = 1; // indicating that first row col zero or not

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) { // It means I have read the
        // previous data so its safe to mark first row and col to zero

        if (i == 0) firstRow = 0; // If zero in first row
        if (j == 0) firstCol = 0;
        //  Marking the first cell of row and col to 0
        matrix[i][0] = 0; // indicates tha t this row has to be 0
        matrix[0][j] = 0;
      }
    }
  }

  //  Iterate over first col
  for (int i = 1; i < n; i++) {
    if (matrix[i][0] == 0) {
      for (int j = 0; j < m; j++) matrix[i][j] = 0;
    }
  }

  //  Over first row
  for (int i = 1; i < m; i++) {
    if (matrix[0][i] == 0) {
      for (int j = 0; j < n; j++) matrix[j][i] = 0;
    }
  }

  //  Also check whether first col or row should be zero
  if (firstCol == 0) {
    for (int i = 0; i < n; i++) matrix[i][0] = 0;
  }

  if (firstRow == 0) {
    for (int i = 0; i < m; i++) matrix[0][i] = 0;
  }

}


