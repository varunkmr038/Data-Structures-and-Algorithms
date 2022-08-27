

void dfs(vector<vector<int>>& graph, int cur, int& dest, vector<int>& path, vector<vector<int>>& ans) {

  path.push_back(cur);

  if (cur == dest) {
    ans.push_back(path);
    path.pop_back();
    return;
  }

  for (auto& nbr : graph[cur]) {
    dfs(graph, nbr, dest, path, ans);
  }
  path.pop_back();
}

//  TIme: O(N^2) Space: O(N) Using dfs exploring all paths
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
// since it is directed acyclic graph no need for vis as there will be no cycle and pointers to parent

  vector<vector<int>> ans;

  int n = graph.size();
  vector<int> path;

  dfs(graph, 0, n - 1, path, ans);

  return ans;
}