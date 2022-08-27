
static bool compare(string& s1, string& s2) {
    return s1.size() < s2.size();
}

bool isChainPossible(string& s1, string& s2) {
    if (s1.size() != s2.size() + 1) return 0;

    int i = 0, j = 0;
    while (i < s1.size()) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        }
        else i++;
    }

    if (i == s1.size() and j == s2.size()) return 1;
    return 0;
}

//  Time: O(N^2*string len + N*Logn) Space: O(N) LIS 1d dp
int longestStrChain(vector<string>& words) {

    int n = words.size();

    sort(words.begin(), words.end(), compare);
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (isChainPossible(words[i], words[j]))
                dp[i] = max(dp[i], dp[j] + 1);

        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// --------------------------------------------------------------------------


static bool compare(string a, string b) {
    return a.size() < b.size();
}

// Time: O(N^2) Space: O(N) 1d DP LIS related
int longestStrChain(vector<string>& words) {

    int n = words.size();
    int ans = 1;

    vector<int> dp(n, 1);
    unordered_map<string, int> mp;


    sort(words.begin(), words.end(), compare);

    for (int i = 0; i < n; i++) {
        mp[words[i]] = i;
    }

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < words[i].size(); j++) {
            string cur = words[i].substr(0, j) + words[i].substr(j + 1);

            if (mp.count(cur)) {
                int idx = mp[cur];

                dp[i] = max(dp[i], dp[idx] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}