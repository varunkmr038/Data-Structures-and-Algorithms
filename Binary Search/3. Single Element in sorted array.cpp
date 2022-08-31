
//  Time: O(N) Space: O()
int singleNonDuplicate(vector<int>& nums) {

	int numSize = nums.size();
	int start = 0, end = numSize - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		// checking iam the single element or not
		if ((mid == 0 or nums[mid] != nums[mid - 1]) and (mid == (numSize - 1) or nums[mid] != nums[mid + 1])) return nums[mid];

		bool isFirst = 0;
		if (mid < (numSize - 1) and nums[mid] == nums[mid + 1]) isFirst = 1; // iam the first occurence

		if (isFirst) {
			// agar first occ even index pe nhi hai mtlb error left me hai
			if (mid % 2 != 0) end = mid - 1;
			else start = mid + 2;
		}
		else {

			// sec occ even index pe mtlb error left me hau
			if (mid % 2 == 0) end = mid - 2;
			else start = mid + 1;
		}
	}


	return 0;
}