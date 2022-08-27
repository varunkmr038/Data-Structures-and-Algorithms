// O(N) based on topological sort
// if we cannot generate topological sort then it is directed cyclic graph
// kahns algorithm topo sort using bfs
void topologicalBFS(vector<vector<int>>& graph, vector<int>& ans) {

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

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    ans.push_back(cur); // topo sort order

    for (auto& nbr : graph[cur]) {
      indegree[nbr]--;

      if (indegree[nbr] == 0)q.push(nbr);
    }
  }

}


//  Time: O(N) Space: O(N)  checking cycle in directed graph using bfs
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> ans;

  vector<vector<int>> graph(numCourses);
  int n = prerequisites.size();

  for (int i = 0; i < n; i++) {

    int course1 = prerequisites[i][0];
    int course2 = prerequisites[i][1];

    graph[course2].push_back(course1);
  }

  topologicalBFS(graph, ans);

  if (ans.size() != numCourses)  // there is  cycle we cannot finish all courses
    return {};

  return ans;
}


