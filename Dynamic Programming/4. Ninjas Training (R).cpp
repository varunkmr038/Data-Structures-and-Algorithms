
int solve(vector<vector<int>>& points, int i, int lastActivity, vector<vector<int>>& dp) {
    int n = points.size();

    if (i == n) return 0;
    if (dp[i][lastActivity] != -1) return dp[i][lastActivity];

    int ans = 0;
    for (int j = 0; j < 3; j++) {
        // i cant do same activity consecutive days
        if (j == lastActivity) continue;

        int sub = points[i][j] +  solve(points, i + 1, j, dp);
        ans = max(ans, sub);
    }
    return dp[i][lastActivity] = ans;
}


//  Time: O(N*4*3) Space: O(N*4) Memoization 2D Dp
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(points, 0, 3, dp);
}


// ------------------------------------------------------------------------


//  Time: O(N*4) Space: O(N*4) Bottom Up 2D Dp
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

// base case
    dp[0][0] = max(points[0][1], points[0][2]); // on 0th day and 0 as last act so dont consider 0 activity
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int days = 1; days < n; days++) {

        for (int lastActivity = 0; lastActivity < 4; lastActivity++) {

            int curAns = 0;
            for (int curActivity = 0; curActivity < 3; curActivity++) {

                // you cant repeat same act
                if (curActivity == lastActivity) continue;

                int meritsEarned = points[days][curActivity] +  dp[days - 1][curActivity];

                curAns = max(curAns, meritsEarned);
            }

            dp[days][lastActivity] = curAns; // it represents that last activity not performed on cur day
        }

    }
    return dp[n - 1][3];
}


// ------------------------------------------------------------------------



//  Time: O(N*4) Space: O(1) Space Optimised Dp
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, 0);

// base case
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int days = 1; days < n; days++) {

        vector<int> temp(4, 0);
        for (int lastActivity = 0; lastActivity < 4; lastActivity++) {

            int curAns = 0;

            for (int curActivity = 0; curActivity < 3; curActivity++) {

                // you cant repeat same act
                if (curActivity == lastActivity) continue;

                int meritsEarned = points[days][curActivity] +  dp[curActivity];

                curAns = max(curAns, meritsEarned);
            }

            temp[lastActivity] = curAns; // it represents that last activity not performed on cur day
        }

        for (int i = 0; i < 4; i++) dp[i] = temp[i];

    }
    return dp[3];
}