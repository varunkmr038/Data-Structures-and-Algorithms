bool isPalindrome(string& s) {
   int n = s.size();

   int i = 0, j = n - 1;
   while (i < j) {
      if (s[i++] != s[j--]) return 0;
   }
   return 1;
}

int solve(string& s, int i, vector<int>& dp) {

   int n = s.size();
   if (i == n) return 0;
   if (dp[i] != -1) return dp[i];

   int ans = INT_MAX;
   string cur = "";
   for (int j = i; j < n; j++) {
      // partition here if cur string is palindrome

      cur += s[j];
      if (isPalindrome(cur)) {
         int sub = solve(s, j + 1, dp) + 1;
         ans = min(ans, sub);
      }
   }
   return dp[i] = ans;
}


//  Time: O(N^2) Space: O(N) Bottom up 1d dp
int minCut(string s) {

   int n = s.size();

   vector<int> dp(n + 1, -1);
   return solve(s, 0, dp) - 1;

}

//----------------------------------------------------------------------------------------

bool isPalindrome(string& s) {
   int n = s.size();

   int i = 0, j = n - 1;
   while (i < j) {
      if (s[i++] != s[j--]) return 0;
   }
   return 1;
}


//  Time: O(N^2) Space: O(N) Bottom up 1d dp
int minCut(string s) {

   int n = s.size();

   vector<int> dp(n + 1, 0);

   for (int i = n - 1; i >= 0; i--) {

      int ans = INT_MAX;
      string cur = "";
      for (int j = i; j < n; j++) {
         // partition here if cur string is palindrome

         cur += s[j];
         if (isPalindrome(cur)) {
            int sub = dp[j + 1] + 1;
            ans = min(ans, sub);
         }
      }

      dp[i] = ans;
   }

   return dp[0] - 1;
}

// -----------------------------------------------------------------------------------------------



void fillPalindromes(string s, vector<vector<bool>>& p) {

   int n = s.size();
   // Inititally P intitialised with 1

   // cases for i<j I have to check which is not palindrome
   for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
         int j = i + len - 1;
         //  If corners are not equal OR My inside is not palindrome
         // then im not palindrome
         if (s[i] != s[j] or p[i + 1][j - 1] == 0)p[i][j] = 0;
      }
   }
}




//  Time: O(N^2) Space: O(N^2) Bottom up 1d dp
int minCut(string s) {

   int n = s.size();

   vector<int> dp(n + 1, 0);
   vector<vector<bool>> p(n, vector<bool>(n, 1));
   fillPalindromes(s, p);

   for (int i = n - 1; i >= 0; i--) {

      int ans = INT_MAX;
      for (int j = i; j < n; j++) {
         // partition here if cur string is palindrome

         if (p[i][j] == 1) {
            int sub = dp[j + 1] + 1;
            ans = min(ans, sub);
         }
      }
      dp[i] = ans;
   }

   return dp[0] - 1;
}