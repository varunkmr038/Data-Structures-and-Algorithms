//  TIme: O(N) Space: O(N) using bfs
int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

//assuming  mx limit on x axis is 1e5
  vector<int> dist(1e5 + 1, INT_MAX);

  // {node,state} state = means forward or backward as we cannot go backward twice in row
  queue<pair<int, int>> q;

  q.push({0, 1}); // state =1 forward
  dist[0] = 0;

  map<int, int> mp;
  for (int i = 0; i < forbidden.size(); i++) mp[forbidden[i]]++;

  while (!q.empty()) {

    auto cur = q.front();
    q.pop();

    if (cur.first == x) break;

    int backNode = cur.first - b;
    int forwardNode = cur.first + a;

    if (backNode > 0 and cur.second == 1 and dist[backNode] == INT_MAX) {
      dist[backNode] = dist[cur.first] + 1;

      if (!mp.count(backNode)) // its a forbidden node
        q.push({backNode, 0});
    }

    if (forwardNode <= 1e5 and dist[forwardNode] == INT_MAX) {
      dist[forwardNode] = dist[cur.first] + 1;

      if (!mp.count(forwardNode)) // its a forbidden node
        q.push({forwardNode, 1});
    }
  }

  return dist[x] == INT_MAX ? -1 : dist[x];
}
