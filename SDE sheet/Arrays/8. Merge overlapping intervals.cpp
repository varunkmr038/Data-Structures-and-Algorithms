

static bool compare(vector<int> a, vector<int> b) {
  return a[0] < b[0];
}

//  Time: O(N*Logn) Space: O(1) Sorting and first last pointers
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> ans;
  int n = intervals.size();

  if (n == 0) return ans;

  sort(intervals.begin(), intervals.end(), compare);


  int first = intervals[0][0], last = intervals[0][1];
  vector<int> v(2);

  for (int i = 1; i < n; i++) {

    if (intervals[i][0] <= last) { // If im overlapping
      last = max(last, intervals[i][1]);
    }

    else {

      v[0] = first;
      v[1] = last;
      ans.push_back(v);

      first = intervals[i][0]; // intitiate new interval
      last = intervals[i][1];
    }
  }

  v[0] = first;
  v[1] = last;

  ans.push_back(v);

  return ans;

}
