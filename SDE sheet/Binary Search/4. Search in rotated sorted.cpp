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