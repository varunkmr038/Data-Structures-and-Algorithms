
//  Time: O(N*Logn) Space: O(K) Sliding Window with Heap
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    int n = nums.size();
    vector<int> ans;

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push({nums[i], i});
    }

    ans.push_back(pq.top().first);

    for (int i = k; i < n; i++) {

        while (!pq.empty() and pq.top().second <= i - k)pq.pop();

        pq.push({nums[i], i});
        ans.push_back(pq.top().first);
    }



    return ans;

}

// ------------------------------------------------------------------

//  Time: O(N) Space: O(N) Sliding Window Deque
vector <int> maxSlidingWindow(vector<int> a, int k)
{   int n = a.size();
    vector<int> ans;
    deque<int> q;

    //  For the first k elements prepare deque and find max
    for (int i = 0; i < k; i++) {
        while (!q.empty()  and a[q.back()] <= a[i])q.pop_back();

        q.push_back(i);

    }

    ans.push_back(a[q.front()]);

    for (int i = k; i < n; i++) {

        // pop out of the windows elements
        while (!q.empty() and q.front() <= i - k)q.pop_front();
        //  If im greater than back then pop the back
        while (!q.empty()  and a[q.back()] <= a[i])q.pop_back();

        q.push_back(i);
        ans.push_back(a[q.front()]);
    }


    return ans;
}