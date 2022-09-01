
#define ll long long int


//  Time: O(N) Space: O(1) Using kadane algo
int maxProduct(vector<int>& nums) {

   int n = nums.size();

   ll ans = nums[0];
   ll maxTillNow = nums[0], minTillNow = nums[0];

   for (int i = 1; i < n; i++) {

      if (nums[i] > 0) {
         ll startNewSub = nums[i];
         ll continueSub = maxTillNow * nums[i];

         maxTillNow = max(startNewSub, continueSub);
         minTillNow = min(startNewSub , minTillNow * nums[i]);
      }
      else {
         ll startNewSub = nums[i];
         ll continueSub = minTillNow * nums[i];

         minTillNow = min(startNewSub, maxTillNow * nums[i]);
         maxTillNow = max(startNewSub, continueSub);
      }

      ans = max(ans, maxTillNow);
   }

   return ans;
}