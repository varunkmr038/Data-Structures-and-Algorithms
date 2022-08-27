void markSnakesLadders(vector<vector<int>>& board, vector<int>& mark, int n) {
  int curNode = 1, turn = 0;
  for (int i = n - 1; i >= 0; i--) {

    // pehli turn me left right jaana
    int j = turn == 0 ? 0 : n - 1;
    while (j<n and  j >= 0) {

      if (board[i][j] != -1)  // snake or ladder
        mark[curNode] = board[i][j];

      curNode++;
      if (turn == 0) j++;
      else j--;
    }
    turn = !turn;
  }
}

void buildGraph(vector<vector<int>>& graph, vector<int>& mark, int n) {

  for (int x = 1; x <= n * n; x++) {
    for (int dice = 1; dice <= 6; dice++) {
      int y = x + dice;
      if (y <= n * n and  mark[y] > 0) y = mark[y]; // cur y pe snake yaa ladder hai

      if (y <= n * n) graph[x].push_back(y);
    }
  }
}

int bfs(vector<vector<int>>& graph, int src, int n) {

  vector<int> dis(n * n + 1, INT_MAX);

  queue<int> q;
  q.push(1);
  dis[1] = 0;

  while (!q.empty()) {

    int cur = q.front();
    q.pop();

    for (auto nbr : graph[cur]) {
      if (dis[nbr] == INT_MAX) {
        dis[nbr] = dis[cur] + 1;
        q.push(nbr);
      }
    }
  }

  return dis[n * n] == INT_MAX ? -1 : dis[n * n];
}

//  Time: O(3*N^2)  Space: O(3*N^2) Using bfs unweighted graph
int snakesAndLadders(vector<vector<int>>& board) {

  int n = board.size();

  // to mark only snakes and ladders
  vector<int> mark(n * n + 1, 0);

  markSnakesLadders(board, mark, n);

  vector<vector<int>> graph(n * n + 1);
  buildGraph(graph, mark, n);

  return bfs(graph, 1, n);
}