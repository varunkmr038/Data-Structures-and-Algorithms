
//  Time: O(N) Space: O(1) Simple using variables
int maxProfit(vector<int>& prices) {

    int n = prices.size();

    int mnDay = prices[0];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, prices[i] - mnDay);
        mnDay = min(mnDay, prices[i]);
    }

    return ans;
}