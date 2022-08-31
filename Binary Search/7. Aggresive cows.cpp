
bool isPossible(vector<int>& books, int students, long long int maxPagesDeadline) {

	long long int countStudents = 1, pages = 0;


	for (int i = 0; i < books.size(); i++) {
		if (books[i] > maxPagesDeadline) return false;

		pages = pages +  1LL * books[i];

		if (pages > maxPagesDeadline) {
			countStudents++;
			pages = books[i];
		}
	}

	return countStudents <= students;
}

//  Time: O(N*Log(sum))  Space: O(1) Using binary search
int Solution::books(vector<int> &books, int students) {

	int low = *max_element(books.begin(), books.end());
	long long int high = 0;

	if (students > books.size()) return -1;

	for (int i = 0; i < books.size(); i++) {
		high = high + 1LL * books[i];
	}

	int ans = -1;

	while (low <= high) {

		long long int maxPagesDeadline = low + (high - low) / 2;

		if (isPossible(books, students, maxPagesDeadline)) {
			ans = maxPagesDeadline;
			high = maxPagesDeadline - 1;
		}
		else low = maxPagesDeadline + 1;
	}
	return ans;
}

