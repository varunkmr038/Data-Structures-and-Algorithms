bool search(string s, vector<string>& wordDict) {

   for (int i = 0; i < wordDict.size(); i++) {
      if (wordDict[i] == s)return 1;
   }

   return 0;
}

bool solve(string s, vector<string>& wordDict, unordered_map<string, bool>& dp) {


   if (s.size() == 0) return 0;

   if (dp.count(s)) return dp[s];

   if (search(s, wordDict)) return dp[s] = 1;

   for (int i = 0; i < s.size() - 1; i++) {

      string left = s.substr(0, i + 1);
      string right = s.substr(i + 1);

      int ans = 0;

      if (search(left, wordDict)) {
         ans = solve(right, wordDict, dp);
      }

      if (ans) return dp[s] = 1;
   }
   return dp[s] = 0;
}



// Time: O(N*S) Space: O(N^2)
bool wordBreak(string s, vector<string>& wordDict) {

   unordered_map<string, bool> dp;
   return solve(s, wordDict, dp);

}

// -------------------------------------------------------------------------------------------------------------


// Time: O(N*S) Space: O(N^2)
bool wordBreak(string s, vector<string>& wordDict) {

   unordered_map<string, bool> dp;
   return solve(s, wordDict, dp);
}



bool solve(string s, vector<string>& wordDict, unordered_map<string, bool>& dp) {

   if (s.size() == 0) return 1;
   if (dp.count(s)) return dp[s];

   for (auto x : wordDict) {

      int len = x.size();
      if (len <= s.size()) {
         string extractword = s.substr(0, len);

         bool ans = 0;
         if (extractword == x) {
            ans = solve(s.substr(len), wordDict, dp);
         }

         if (ans) return dp[s] = 1;
      }
   }
   return dp[s] = 0;
}


// ---------------------------------------------------------------------------------------------------

