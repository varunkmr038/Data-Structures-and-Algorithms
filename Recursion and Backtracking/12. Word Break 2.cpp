void solve(string& s, vector<string>& wordDict, int i, string cur, unordered_map<string, int>& mp, vector<string>& ans) {

	int n = s.size();

	if (i == n) {
		cur.pop_back();
		ans.push_back(cur);
		return ;
	}
	string t;
	for (int j = i; j < n; j++) {
		t.push_back(s[j]);

		// check given word exist in the worddict
		if (mp.count(t)) {
			t.push_back(' ');
			solve(s, wordDict, j + 1, cur + t, mp, ans);
			t.pop_back();
		}
	}

}


//  Time: O(2^N) Space: O(N) Backtracking
vector<string> wordBreak(string s, vector<string>& wordDict) {

	vector<string> ans;
	unordered_map<string, int> mp;

	for (int i = 0; i < wordDict.size(); i++) mp[wordDict[i]]++;

	string cur;
	solve(s, wordDict, 0, cur, mp, ans);

	return ans;
}
