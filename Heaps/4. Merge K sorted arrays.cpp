
//  Time: O(K^2*LogK) Space: O(K) Priority queue
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{

  vector<int> ans(K * K);
  int idx = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  vector<int> index(K, 0);

  // Push all the first elements with respective index
  for (int i = 0; i < K; i++)pq.push({arr[i][0], i});

  while (idx < K * K) {

    pair<int, int> p = pq.top();
    pq.pop();

    ans[idx++] = p.first;
    int curIdx = p.second;
    index[curIdx]++;
    if ( index[curIdx] < K)
      pq.push({arr[curIdx][index[curIdx]], curIdx});
  }



  return ans;
}
