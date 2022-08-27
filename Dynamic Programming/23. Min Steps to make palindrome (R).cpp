
int solve(string& s, int i, int j, vector<vector<int>>& dp) {

    // no insertions required
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    if (s[i] == s[j]) ans = solve(s, i + 1, j - 1, dp); // just match them
    else {
        int insertCharAtRight = 1 + solve(s, i + 1, j, dp); // inserting left char at right end to match
        int insertCharAtLeft = 1 + solve(s, i, j - 1, dp); // inserting right char at left end to match

        ans = min(insertCharAtLeft, insertCharAtRight);
    }

    return dp[i][j] = ans;
}


//  TIme: O(N*N)  Space: O(N*N) Memoized  2d Dp
int minInsertions(string s) {

    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(s, 0, n - 1, dp);
}

// -----------------------------------------------------------------------------------------------------------------

// leetcode max insertion to make palindrome will be  leetcode edocteel s + rev(s)
// but we have to find minimum
// leetcode lps = 3 So min insertioms = len - lps =8 - 3 = 5

int longestPalindromeSubseq(string s) {

    int n = s.size();

    vector<int> dp(n + 1, 0);
    dp[n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {

        vector<int> temp(n + 1, 0);
        temp[i] = 1; // i=j case

        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) temp[j] += 2 + dp[j - 1];
            else temp[j] += max(temp[j - 1], dp[j]);
        }

        dp = temp;
    }

    return dp[n - 1];
}


//  TIme: O(N*N)  Space: O(N) Bottom Up  1d Dp
int minInsertions(string s) {

    int n = s.size();
    return n - longestPalindromeSubseq(s);
}

// -----------------------------------------------------------------------------------------------------------------