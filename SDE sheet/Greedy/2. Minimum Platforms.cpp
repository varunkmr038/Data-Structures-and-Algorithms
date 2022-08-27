
//  Time: O(N*Logn) Space: O(N) Using sorting and priority queue
int findPlatform(int arr[], int dep[], int n)
{
  //  min heap
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<pair<int, int>> time;

  for (int i = 0; i < n; i++) time.push_back({arr[i], dep[i]});
  sort(time.begin(), time.end());

  int ans = 1;
  pq.push(time[0].second);

  for (int i = 1; i < n; i++) {

    // sbse km  dept time wali train ka time km hau mere arrival se
    // to wo leave kr jayengi platform
    while (!pq.empty() and pq.top() < time[i].first) pq.pop();

    pq.push(time[i].second);
    ans = max(ans, pq.size());
  }
  return ans;
}

// ---------------------------------------------------------------------------------

//  Time: O(N*Logn) Space: O(N) Using creating arrival and dept timeline
int findPlatform(int arr[], int dep[], int n)
{
  vector<pair<int, int>> time;

  for (int i = 0; i < n; i++) {
    time.push_back({arr[i], 0}); // arrival
    time.push_back({dep[i], 1}); // dept
  }

  sort(time.begin(), time.end());

  int ans = 0, curTrains = 0;

  for (int i = 0; i < time.size(); i++) {

    if (time[i].second == 0) curTrains++; // arrival of train
    else curTrains--; // dept

    ans = max(ans, curTrains);
  }

  return ans;
}


// --------------------------------------------------------------------------

//  Time: O(N*Logn) Space: O(1) Without Using  Extra space
int findPlatform(int arr[], int dep[], int n)
{
  sort(arr, arr + n);
  sort(dep, dep + n);

  int ans = 0, platNeeded = 0;
  int i = 0, j = 0;

  while (i < n and j < n) {

    if (arr[i] <= dep[j]) {
      i++;
      platNeeded++;
    }

    else {
      j++;
      platNeeded--;
    }

    ans = max(ans, platNeeded);
  }
  return ans;
}