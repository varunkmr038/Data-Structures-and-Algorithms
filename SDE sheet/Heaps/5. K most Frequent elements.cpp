
//  Time: O(N*logn)  Space: O(N) using heap
vector<int> topKFrequent(vector<int>& nums, int k) {
  vector<int> ans;
  int n = nums.size();
  unordered_map<int, int> mp;


  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    mp[nums[i]]++;

  }

  for (auto x : mp) {
    q.push({x.second, x.first});
  }

  while (k != 0) {

    ans.push_back(q.top().second);
    q.pop();
    k--;
  }


  return ans;
}