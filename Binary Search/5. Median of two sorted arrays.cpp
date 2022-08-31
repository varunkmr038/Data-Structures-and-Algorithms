//  Time: O(Logn) Space: O(1) Binary Search
int search(vector<int>& nums, int target) {

	int n = nums.size();

	int start = 0, end = n - 1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (nums[mid] == target) return mid;

		// my left half is sorted
		else if (nums[start] <= nums[mid]) {

			// if target lies in between left half
			if (target >= nums[start] and target <= nums[mid]) end = mid - 1;
			else start = mid + 1;

		}

		// my right half is sorted
		else {

			if (target >= nums[mid] and target <= nums[end]) start = mid + 1;
			else end = mid - 1;
		}
	}
	return -1;
}

// ----------------------------------------------------------------------------------------------


// O(N)
double merge(vector<int>& a, vector<int>& b) {

	//Dont need to store all elements in array as
	// only middle elements are required for median
	int m = a.size(), n = b.size();
	int i = 0, j = 0, k = 0;
	int ele1 = 0, ele2 = 0; //  middle elements

	while (i < m and j < n) {

		if (a[i] < b[j]) {
			if (k == ((m + n) / 2) - 1)
				ele1 = a[i];
			else if (k == (m + n) / 2) ele2 = a[i];
			i++;
		}

		else {
			if (k == ((m + n) / 2) - 1)
				ele1 = b[j];
			else if (k == (m + n) / 2) ele2 = b[j];
			j++;
		}

		k++;
	}

	for (; i < m; i++) {
		if (k == ((m + n) / 2) - 1)
			ele1 = a[i];
		else if (k == (m + n) / 2) ele2 = a[i];
		k++;
	}

	for (; j < n; j++) {
		if (k == ((m + n) / 2) - 1)
			ele1 = b[j];
		else if (k == (m + n) / 2) ele2 = b[j];
		k++;
	}

	cout << ele1 << " " << ele2;
	if ((m + n) % 2 == 0) {
		return (double)(ele1 + ele2) / 2;
	}
	else return ele2 * 1.0;
}

// Time: O(N) Space: O(1) Merging the two sorted arrays without storing all elements
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	// Median = middle in sorted array
	double ans = 0;
	int n = nums1.size() + nums2.size();

	ans = merge(nums1, nums2);

	return ans;
}

// ---------------------------------------------------------------------------------------------------

// Time: O(log(m+n)) Space: O(1) Binary Search by making cuts on nums1
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	//  I want nums2 to bigger as If im taking 0 ele from nums1
	// then i can take half from nums2
	if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

	int n1 = nums1.size(), n2 = nums2.size();
	int low = 0, high = n1;  // n1<=(n1+n2)/2

	while (low <= high) {

		int cut1 = (low + high) / 2;  // on nums1
		int cut2 = (n1 + n2 + 1) / 2 - cut1;

		int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1]; //last before cut nums1
		int l2 =  cut2 == 0 ? INT_MIN : nums2[cut2 - 1]; // cut2==0 means taking 0 ele from nums2

		int r1 = cut1 == n1 ? INT_MAX : nums1[cut1]; // after cut value nums1
		int r2 = cut2 == n2 ? INT_MAX : nums2[cut2]; // cut=n2 means taking full nums2

		if (l1 <= r2 and l2 <= r1) {
			if ((n1 + n2) % 2 == 0)
				return ((double)(max(l1, l2) + min(r1, r2)) / 2);

			else return max(l1, l2);
		}

		else if (l1 > r2) high = cut1 - 1;  // I have decrease l1 and increase r2
		else low = cut1 + 1;

	}

	return 0.0;
}