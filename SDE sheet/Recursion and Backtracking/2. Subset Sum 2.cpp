
void solve(vector<int>& nums, int i, vector<int>& curSubset, set<vector<int>>& st) {
	int numSize = nums.size();

	if (i == numSize) {
		st.insert(curSubset);
		return;
	}

	curSubset.push_back(nums[i]);
	solve(nums, i + 1, curSubset, st);

	curSubset.pop_back();
	solve(nums, i + 1, curSubset, st);
}

//  Time: O(2^N*N*Logn)  Space: O(2^N) using recursion and set for duplicacy
vector<vector<int>> subsetsWithDup(vector<int>& nums) {

	int numSize = nums.size();

	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	set<vector<int>> st;

	vector<int> subset;
	solve(nums, 0, subset, st);

	for (auto& x : st) ans.push_back(x);

	return ans;
}

// -----------------------------------------------------------------------------------------

void solve(vector<int>& nums, int i, vector<int>& curSubset, vector<vector<int>>& ans ) {

	int numSize = nums.size();

	if (i == numSize) {
		ans.push_back(curSubset);
		return;
	}

	int curValue = nums[i];

	curSubset.push_back(curValue);
	solve(nums, i + 1, curSubset, ans);

	curSubset.pop_back();

// if not including cur num then  skip all the cur num and move to next
// otherwise it will lead to duplicate

	while (i < numSize and nums[i] == curValue) i++;

	solve(nums, i + 1, curSubset, ans);
}

//  Time: O(2^N)  Space: O(2^N) using recursion and without set
vector<vector<int>> subsetsWithDup(vector<int>& nums) {

	int numSize = nums.size();

	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;

	vector<int> subset;
	solve(nums, 0, subset, ans);

	return ans;
}