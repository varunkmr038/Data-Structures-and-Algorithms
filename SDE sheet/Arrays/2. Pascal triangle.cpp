

//  Time: O(N^2) Space: O(N^2) Simply generate triangle
vector<vector<int>> generate(int numRows) {

  vector<vector<int>> ans;


  for (int i = 0; i < numRows; i++) {
    vector<int> a;

    for (int j = 0; j <= i; j++) {
      if (j == 0 or j == i) a.push_back(1);

      else a.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
    }

    ans.push_back(a);
  }

  return ans;

}