//  Time: O(2^N) Space: O(N) Backtracking Brute
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

	vector<vector<int>> ans;

	vector<int> cur;
	solve(candidates, 0, target, cur, ans);

	return ans;
}


void solve(vector<int>& candidates, int i, int target, vector<int>& cur , vector<vector<int>>& ans) {
	int n = candidates.size();

	if (i == n) {
		// combination found
		if (target == 0) ans.push_back(cur);
		return ;
	}

	if (target == 0) {
		ans.push_back(cur);
		return ;
	}
	// not valid
	if (target < 0) return ;

	// exclude current
	solve(candidates, i + 1, target, cur, ans);

	// include current infinte times
	cur.push_back(candidates[i]);
	solve(candidates, i, target - candidates[i], cur, ans);

	// this is imp to send cur as by reference
	// improves time complexity
	cur.pop_back();
}