//  Time: O(N^2) Space: O(1) Brute force
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> ans(n1);
    for (int i = 0; i < n1; i++) {
        int cur = -1;
        for (int j = 0; j < n2; j++) {
            if (nums2[j] == nums1[i]) {
                while (j < n2) {
                    if (nums2[j] > nums1[i]) {
                        cur = nums2[j];
                        break;
                    }
                    j++;
                }
            }
        }
        ans[i] = cur;
    }

    return ans;
}

// --------------------------------------------------------------


//  Time: O(N) Space: O(N) Using Stack and unordered map
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> ans(n1);
    unordered_map<int, int> mp;
    stack<int> s;

    for (int i = 0; i < n2; i++) {

        while (!s.empty() and nums2[i] >= nums2[s.top()]) {
            mp[nums2[s.top()]] = nums2[i];
            s.pop();
        }

        s.push(i);

    }

    while (!s.empty()) {

        mp[nums2[s.top()]] = -1;
        s.pop();

    }

    for (int i = 0; i < n1; i++) ans[i] = mp[nums1[i]];

    return ans;
}
