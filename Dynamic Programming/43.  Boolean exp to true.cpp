int M = 1000000007;

long long solve(string& s, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp) {

    if (i > j) return 0;
    if (i == j) {
        // if trueOrFalse=1 then we are looking for T
        if (isTrue == 1) return s[i] == 'T';
        else return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];


    int ans = 0;
    // only traversing the operators
    for (int k = i + 1; k <= j - 1; k += 2) {

        // it is operator partition here
        long long leftTrue = solve(s, i, k - 1, 1, dp);
        long long leftFalse = solve(s, i, k - 1, 0, dp);
        long long rightTrue = solve(s, k + 1, j, 1, dp);
        long long rightFalse = solve(s, k + 1, j, 0, dp);

        if (s[i] == '^') {
            if (isTrue) {
                ans = (ans +  (leftFalse * rightTrue) % M) % M; // F T
                ans = (ans + (leftTrue * rightFalse) % M) % M; // T F
            }
            else {
                ans = (ans + (leftTrue * rightTrue) % M) % M; // T T
                ans = (ans + (leftFalse * rightFalse) % M) % M; // F F
            }
        }
        else if (s[i] == '&') {
            if (isTrue)
                ans = (ans + (leftTrue * rightTrue) % M) % M; // T T
            else ans = (ans + (leftFalse * rightFalse) % M + (leftFalse * rightTrue) % M + (leftTrue * rightFalse) % M) % M; // F F + F T + T F
        }
        else {
            // or operator
            if (isTrue) {
                ans =  (ans + (leftTrue * rightTrue) % M) % M; // T T
                ans = (ans + (leftFalse * rightTrue) % M) % M; // F T
                ans = (ans + (leftTrue * rightFalse) % M) % M; // T F
            }
            else ans = (ans + (leftFalse * rightFalse) % M) % M; // F F
        }
    }
    return dp[i][j][isTrue] = ans;
}

//  Time: O(N^3)  Space: O(2*N^2) Memoized 3d Dp
int evaluateExp(string& s) {

    int n = s.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    long long ans = solve(s, 0, n - 1, 1, dp);

    return ans;
}
