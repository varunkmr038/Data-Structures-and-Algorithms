//Time: O(M*N)  Space: O(1);
bool searchMatrix(vector<vector<int>>& matrix, int target) {

  int m = matrix.size(), n = matrix[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {

      if (matrix[i][j] == target) return true;
    }
  }



  return false;

}


// -----------------------------------------------------------------------------


bool binarysearch(vector<int> a, int n, int target) {

  int l = 0, h = n - 1;

  while (l <= h) {

    int mid = (l + h) / 2;

    if (a[mid] == target) return true;
    else if (a[mid] > target) h = mid - 1;
    else l = mid + 1;

  }
  return false;

}


//Time: O(M*Logn)  Space: O(1);
bool searchMatrix(vector<vector<int>>& matrix, int target) {

  int m = matrix.size(), n = matrix[0].size();

  for (int i = 0; i < m; i++) {

    if (binarysearch(matrix[i], n, target)) return true;

  }
  return false;

}

// ----------------------------------------------------------------

//Time: O(N)  Space: O(1) Staircase search
bool searchMatrix(vector<vector<int>>& matrix, int target) {

  int m = matrix.size(), n = matrix[0].size();

  int i = 0, j = n - 1;

  while (i<m and j >= 0) {

    if (matrix[i][j] == target) return true;
    else if (matrix[i][j] > target) j--;
    else i++;
  }



  return false;

}