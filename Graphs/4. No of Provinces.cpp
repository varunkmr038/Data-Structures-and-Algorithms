
void dfs(vector<vector<int>>& isConnected, int cur, vector<int>& vis) {

  vis[cur] = 1;

  // O(N)
  for (int i = 0; i < isConnected[cur].size(); i++) {
    if (isConnected[cur][i] == 0) continue; // no edge in between them

    if (!vis[i]) dfs(isConnected, i, vis);
  }

}


//  Time: O(N^2) Space: O(N)  Using dfs
int findCircleNum(vector<vector<int>>& isConnected) {

  int n = isConnected.size();
  vector<int> vis(n, 0);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(isConnected, i, vis);
      ans++;
    }
  }
  return ans;
}

// ---------------------------------------------------------------------------

class DSU {
public:

  int components;
  vector<int> parent;

  DSU(int n) {
    components = n;

    parent.resize(n);
    for (int i = 0; i < n; i++)parent[i] = i;
  }

  int getSuperParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getSuperParent(parent[x]);
  }

  void unite(int x, int y) {

    int superX = getSuperParent(x);
    int superY = getSuperParent(y);

    if (superX != superY) {
      components--;
      parent[superX] = superY;
    }
  }

};


//  Time: O(N^2) Space: O(N) Using dsu union find
int findCircleNum(vector<vector<int>>& isConnected) {

  int n = isConnected.size();

  DSU ds = new DSU(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (isConnected[i][j] == 0) continue;

      ds->unite(i, j);
    }
  }

  return ds->components;
}