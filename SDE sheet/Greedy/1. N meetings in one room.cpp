
bool static compare(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

//  Time: O(N*Logn)  Space: O(1) Sorting based on meeting end time
int maxMeetings(int start[], int end[], int n)
{
  vector<pair<int, int>> meetings;

  for (int i = 0; i < n; i++) meetings.push_back({start[i], end[i]});

  sort(meetings.begin(), meetings.end(), compare);

  int first = meetings[0].first, last = meetings[0].second;

  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (meetings[i].first > last) {
      ans++;
      first = meetings[i].first;
      last = meetings[i].second;
    }
  }
  return ans;
}