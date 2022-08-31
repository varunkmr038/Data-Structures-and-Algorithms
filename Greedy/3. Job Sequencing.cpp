static bool compare(Job a, Job b) {

  return a.profit > b.profit;

}

//  Time: O(N^2) Space: O(N) Greedy
vector<int> JobScheduling(Job arr[], int n)
{

  // intuition is highest profit job ko lena hai or usse deadline pe krna hau
  // agar deadline nhi hau to usse neeche wale time pe kro
  sort(arr, arr + n, compare);

  vector<int> ans;
  int jobs = 0, profit = 0;

  bool mp[n] = {0};

  for (int i = 0; i < n; i++) {
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
      if (!mp[j]) {
        jobs++;
        profit += arr[i].profit;
        mp[j] = 1;
        break;

      }
    }
  }

  ans.push_back(jobs);
  ans.push_back(profit);

  return ans;
}

