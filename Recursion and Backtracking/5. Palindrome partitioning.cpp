bool isValid(string& s, int n, unordered_map<string, bool>& mp) {

	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) return  mp[s] = 0;
	}



	return mp[s] = 1;
}

void solve(string& s, int i, int& n, vector<string> v, vector<vector<string>>& ans,
           unordered_map<string, bool>& mp) {

	if (i == n) {
		ans.push_back(v);
		return;
	}

	for (int len = 1; len <= n - i; len++) {

		string cur = s.substr(i, len);



		if ((!mp.count(cur)  and isValid(cur, cur.size(), mp)) or mp[cur] == 1) {
			v.push_back(cur);
			solve(s, i + len, n, v, ans, mp);
			v.pop_back();
		}
	}

}

//  Time: O(2^N) Space: O(N) Simple backtracking
vector<vector<string>> partition(string s) {

	vector<vector<string>> ans;

	int n = s.size();
	vector<string> v;
	unordered_map<string, bool> mp;
	solve(s, 0, n, v, ans, mp);

	return ans;

}