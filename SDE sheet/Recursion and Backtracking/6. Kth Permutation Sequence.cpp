
//
void solve(string nums, string& cur, string& ans, int& idx, int& k) {

	if (nums.size() == 0) {
		idx++;
		if (idx == k) ans = cur; // this is kth permutation
	}


	for (int i = 0; i < nums.size(); i++) {

		string restString = nums.substr(0, i) + nums.substr(i + 1);
		cur.push_back(nums[i]);

		solve(restString, cur, ans, idx, k);
		if (ans != "") return;
		cur.pop_back();
	}

}

//  Time: O(N!)  Space: O(N) Recursion and backtracking
string getPermutation(int n, int k) {

	string nums = "";
	for (int i = 1; i <= n; i++) nums += to_string(i);

	string ans = "";
	int idx = 0;

	string cur = "";
	solve(nums, cur, ans, idx,  k);

	return ans;
}

// ---------------------------------------------------------------------------------------

//  Time: O(N^2)  Space: O(N) using maths
string getPermutation(int n, int k) {

	string ans = "";
	int fact = 1;

	string nums = "";
	for (int i = 1; i < n; i++) {
		nums.push_back(i);
		fact *= i;
	}

	nums.push_back(n);
	k--; // 0 based indexing

	while (true) {

		ans += to_string(nums[k / fact]);
		nums.erase(nums.begin() + k / fact); // O(N)

		if (nums.size() == 0) break;

		k = k % fact;
		fact /= nums.size();
	}

	return ans;
}
