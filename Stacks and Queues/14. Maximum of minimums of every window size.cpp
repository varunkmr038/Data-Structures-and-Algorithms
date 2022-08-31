
//  Time: O(N^2)  Space: O(1) Brute force
vector <int> maxOfMin(int arr[], int n)
{
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {

        int minTillNow = INT_MAX;
        for (int j = i; j < n; j++) {
            minTillNow = min(minTillNow, arr[j]);

            int windowSize = j - i + 1;
            ans[windowSize - 1] = max(ans[windowSize - 1], minTillNow);
        }
    }
    return ans;
}

// ---------------------------------------------------------------------------

