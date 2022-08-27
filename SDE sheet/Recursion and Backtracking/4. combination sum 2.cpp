//  Time: O(2^N) Space: O(N) Backtracking Brute
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

	vector<vector<int>> ans;

	sort(candidates.begin(), candidates.end());

	vector<int> cur;
	solve(candidates, 0, target, cur, ans);


	return ans;
}

void solve(vector<int>& candidates, int i, int target, vector<int>& cur, vector<vector<int>>& ans) {
	int n = candidates.size();

	if (i == n) {
		if (target == 0) ans.push_back(cur);
		return;
	}

	if (target < 0) return;
	if (target == 0) {
		ans.push_back(cur);
		return ;
	}

	// exclude
	// if excluding dont consider similar numbers
	// 1 1 1 1 1 2  -- agar pehla 1 exclude kru toh 2nd 3rd 4th se start hi nhi krna
	// seedhe 2 se start krna isse duplicacy remove hongi
	// kyuki exclude hi is liye kr rhe hai kyuki wo number hi consider na kru

	int j = i;
	while (j < n - 1) {
		if (candidates[j] != candidates[j + 1]) break;
		j++;
	}

	solve(candidates, j + 1, target, cur, ans);

	//include
	cur.push_back(candidates[i]);
	solve(candidates, i + 1, target - candidates[i], cur, ans);

	cur.pop_back();
}