void solve(vector<int>& nums, vector<vector<int>>& ans, int i) {
	int n = nums.size();

	if (i == n) {
		ans.push_back(nums);
		return ;
	}

	for (int j = i; j < n; j++) {
		swap(nums[j], nums[i]);

		solve(nums, ans, i + 1);

		swap(nums[j], nums[i]);
	}

}


//  Time: O(N*N!) Space: O(N) Backtracking
vector<vector<int>> permute(vector<int>& nums) {

	vector<vector<int>> ans;

	solve(nums, ans, 0);

	return ans;
}