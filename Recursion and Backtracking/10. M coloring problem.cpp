

bool isValidColor(bool graph[101][101], int color, int cur, int V, vector<int>& colors) {

	for (int i = 1; i <= V; i++) {
		if (graph[cur - 1][i - 1] == 1 and colors[i] == color) {
			return 0;
		}
	}
	return 1;
}

bool solve(bool graph[101][101], int m, int cur, int V, vector<int>& colors) {

	if (cur > V) return 1;

	for (int i = 1; i <= m; i++) {

		if (isValidColor(graph, i, cur, V, colors)) {
			colors[cur] = i;
			bool success = solve(graph, m, cur + 1, V, colors);

			if (success) return 1;

			colors[cur] = 0;
		}

	}

	return 0;
}

//  Time: O(M^N) Space: O(N)
bool graphColoring(bool graph[101][101], int m, int V)
{
	vector<int> colors(V + 1, 0);
	return solve(graph, m, 1, V, colors);
}
