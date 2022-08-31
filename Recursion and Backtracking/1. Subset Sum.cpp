
void solve(vector<int>& arr, int i, vector<int>& ans, int curSum) {

	if (i == arr.size()) {
		ans.push_back(curSum);
		return;
	}

	solve(arr, i + 1, ans, curSum + arr[i]);
	solve(arr, i + 1, ans, curSum);
}


//  Time: O(2^N)  Space:  O(2^N) Brute recursion
vector<int> subsetSums(vector<int> arr, int N)
{
	vector<int> ans;

	solve(arr, 0, ans, 0);

	sort(ans.begin(), ans.end());
	return ans;
}