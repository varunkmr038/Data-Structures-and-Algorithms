void dfs(vector<vector<int>>& graph, int cur, vector<int>& col, bool& oddCycle) {

  for (auto& nbr : graph[cur]) {
    // not visited
    if (col[nbr] == 0) {
      col[nbr] = 3 - col[cur];
      dfs(graph, nbr, col, oddCycle);
    }

    else if (col[cur] == col[nbr]) oddCycle = 1;

    if (oddCycle) return ;
  }

}


//  Time: O(N) Space: O(N) USing dfs
bool isBipartite(vector<vector<int>>& graph) {

  int n = graph.size();

  // if there is odd len cycle then bipartite
  vector<int> col(n, 0);

  for (int i = 0; i < n; i++) {
    bool oddCycle = 0;
    if (col[i] == 0) {
      col[i] = 1;
      dfs(graph, i, col, oddCycle);
    }

    if (oddCycle) return false; // not bipartite
  }

  return true;
}