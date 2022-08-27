

long long solve(int arr[], int i, int n, int k) {

	if (i == n) return 0;

	// I have one painter left so he will paint the rest
	if (k == 1) {
		return accumulate(arr + i, arr + n, 0); // rest sum
	}

	long long ans = INT_MAX;
	// try to partion at every point
	long long sum = 0;
	while (i < n) {

		sum += arr[i];
		long long partitionHere = solve(arr, i + 1, n, k - 1);

		ans = min(ans, max(sum, partitionHere)); // ho skta hau max time is painter ka ho
		i++;
	}
	return ans;
}

//  Time: O(N^K)  Space: O(N) Brute force recursion
long long minTime(int arr[], int n, int k)
{
	return solve(arr, 0, n, k);

}

/// ------------------------------------------------------------------------------------------------------


long long solve(int arr[], int i, int n, int k, vector<vector<long long>>& dp) {

	if (i == n) return 0;

	if (dp[i][k] != -1) return dp[i][k];

	// I have one painter left so he will paint the rest
	if (k == 1) {
		return dp[i][k] = accumulate(arr + i, arr + n, 0); // rest sum
	}

	long long ans = INT_MAX;
	// try to partion at every point
	long long sum = 0;
	while (i < n) {

		sum += arr[i];
		long long partitionHere = solve(arr, i + 1, n, k - 1, dp);

		ans = min(ans, max(sum, partitionHere));
		i++;
	}
	return dp[i][k] = ans;
}

//  Time: O(N^2*K)  Space: O(N*K) Using 2d Dp
long long minTime(int arr[], int n, int k)
{
	vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
	return solve(arr, 0, n, k, dp);

}

// ----------------------------------------------------------------------------------------

bool isPossible(int arr[], int n, int k, int curDeadline) {

	long long painters = 1, painterTime = 0;

	for (int i = 0; i < n; i++) {
		painterTime = painterTime +  1LL * arr[i];

		if (painterTime > curDeadline) {
			painters++;
			painterTime = arr[i];

			if (painters > k) return false;
		}
	}

	return true;
}

//  Time: O(N*log(sum))  Space: O(1) Using Binary Search
long long minTime(int arr[], int n, int k)
{
	long long ans = 0;

	long long low = *max_element(arr, arr + n);
	long long high = accumulate(arr, arr + n, 0);

	while (low <= high) {

		long long  curDeadline = low +  (high - low) / 2;

		if (isPossible(arr, n, k, curDeadline)) {
			ans = curDeadline;
			high = curDeadline - 1;
		}

		else low = curDeadline + 1;
	}

	return ans;
}
