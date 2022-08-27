
//  Time: O(N*M*Logn) Space: O(N*M) Using extra space and sorting
int Solution::findMedian(vector<vector<int> > &mat) {

	vector<int> a;
	int m = mat.size(), n = mat[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) a.push_back(mat[i][j]);
	}

	sort(a.begin(), a.end());

	return a[(n * m) / 2];
}

// ---------------------------------------------------------------------------------------------
//https://www.youtube.com/watch?v=79S7C6pvl2E&t=554s
//  Time: O(log(10^9)*m*logn) Space: O(1) binary search on search space 1 - 1e9
int Solution::findMedian(vector<vector<int> > &mat) {

	int m = mat.size(), n = mat[0].size();

	int total = n * m;
	int ans = 0;

	// checking each number that how many number on left of it and how many on right in each col
	// since its sorted
	// if left == right  yhi median

	int low = 0, high = INT_MAX;

	while (low <= high) {
		int curNum = low + (high - low) / 2;

		// check krna kitne bande on left hai or kitne on right
		int right = 0;
		for (int i = 0; i < m; i++) {
			int count =  mat[i].end() - lower_bound(mat[i].begin(), mat[i].end(), curNum) ; //>= curNum
			right += count;
		}

		int mereLeft = total - right; // mere se less than wale < curnum

		// kyuki ho skta hau num exist hi nhi krta then in that case ans right me hi hoga
		if (mereLeft <= (total / 2)) {
			low = curNum + 1;
			ans = curNum; // mere se left me ans exist nhi kr skta to yaa to mai hu yaa right me hai asli ans

		}
		else high = curNum - 1;
	}

	return ans;
}

