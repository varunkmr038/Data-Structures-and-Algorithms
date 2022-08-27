/*
                a c e
              a 3 2 1 0
              b 2 2 1 0
              c 2 2 1 0
              d 1 1 1 0
              e 1 1 1 0
                0 0 0 0
*/

int longestCommonSubsequence(string text1, string text2, vector<vector<int>>& dp) {

    int m = text1.size(), n = text2.size();

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int ans = 0;

            if (text1[i] == text2[j]) ans = 1 + dp[i + 1][j + 1];
            else {
                int sub1 = dp[i + 1][j];
                int sub2 = dp[i][j + 1];
                ans = max(sub1, sub2);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

//  TIme: O(N*M)  Space: O(N*M) Bottom Up 2d Dp
string printLCS(string text1, string text2) {

    int m = text1.size(), n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    longestCommonSubsequence(text1, text2, dp);

    string ans = "";
    int i = 0, j = 0;

    while (i < m and j < n) {

        if (text1[i] == text2[j]) {
            ans += text1[i];
            i++;
            j++;
        }
        else {
            if (dp[i + 1][j] > dp[i][j + 1]) i++;
            else j++;
        }
    }
    return ans;
}

// --------------------------------------------------------------------------------


