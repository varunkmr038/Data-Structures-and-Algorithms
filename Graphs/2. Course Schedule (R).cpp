// O(N)
bool detectCycle(vector<vector<int>>& graph, int curCourse, vector<int>& vis) {

  vis[curCourse] = 1;

  for (auto x : graph[curCourse]) {
    if (vis[x] == 0) {
      if (detectCycle(graph, x, vis) == true) return true;
    }
    else if (vis[x] == 1) return true;

  }
  vis[curCourse] = 2;

  return false;
}


//  Time: O(N) Space: O(N) DFS checking cycle in directed graph using dfs
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

  vector<vector<int>> graph(numCourses);
  int n = prerequisites.size();

  for (int i = 0; i < n; i++) {

    int course1 = prerequisites[i][0];
    int course2 = prerequisites[i][1];

    graph[course1].push_back(course2);
  }

  vector<int> vis(numCourses, 0);

  bool ans;

  for (int i = 0; i < numCourses; i++) {
    if (vis[i] == 1) continue;

    ans = detectCycle(graph, i, vis);
    if (ans) return false;

  }
  return true;
}

// ----------------------------------------------------------------------------

// O(N) based on topological sort
// if we cannot generate topological sort then it is directed cyclic graph
// kahns algorithm topo sort using bfs
bool detectCycleBFS(vector<vector<int>>& graph) {

  int n = graph.size();

  vector<int> indegree(n, 0);

  for (int i = 0; i < n; i++) {
    for (auto& nbr : graph[i]) {
      indegree[nbr]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) q.push(i);
  }

  int cnt = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    cnt++;

    for (auto& nbr : graph[cur]) {
      indegree[nbr]--;

      if (indegree[nbr] == 0)q.push(nbr);
    }
  }

  if (cnt == n) return false; // there is no  cycle
  return true;
}


//  Time: O(N) Space: O(N)  checking cycle in directed graph using BFS
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

  vector<vector<int>> graph(numCourses);
  int n = prerequisites.size();

  for (int i = 0; i < n; i++) {

    int course1 = prerequisites[i][0];
    int course2 = prerequisites[i][1];

    graph[course1].push_back(course2);
  }


  bool ans = detectCycleBFS(graph);

  if (ans) return false; //if there is cycle
  return true;
}