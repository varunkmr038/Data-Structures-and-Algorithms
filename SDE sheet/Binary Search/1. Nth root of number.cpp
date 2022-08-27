//  log p
long long int pow(long long int n, long long int p) {
	if (p == 0) return 1;

	if (p % 2 == 0) return pow(n, p / 2) * pow(n, p / 2);
	else return pow(n, p / 2) * pow(n, p / 2) * n;
}

//  Time: O(logn*logm) Space: O(1)
long long int NthRoot(long long int n, long long int m)
{
	if (n == 1) return m;
	if (n == 2) return sqrt(m);

	long long int low = 0, high = cbrt(m);

	while (low <= high) {

		long long int curNum = low + (high - low) / 2;

		long long int val = pow(curNum, n);

		if (val == m) return curNum;
		else if (val < m) low = curNum + 1;
		else high = curNum - 1;
	}

	return -1;
}
