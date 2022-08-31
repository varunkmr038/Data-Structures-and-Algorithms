#include<bits/stdc++.h>
using namespace std;

#define t()             int t; cin>>t; while(t--)
#define ff              first
#define ss              second
#define int             long long int
#define mod             1000000007
#define pb              push_back
#define inf             1e18
typedef pair<int, int>   pii;

void c_p_c() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);
#endif
}


class minHeap {

  vector<int> arr;

public:


  Heap(vector<int>& arr) {
    this->arr = arr;
  }

  void heapify(int idx) {

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int minIdx = idx;

    if (left < arr.size() and arr[left] < arr[minIdx])
      minIdx = left;

    if (right < arr.size() and arr[right] < arr[minIdx])
      minIdx = right;

    if (minIdx != idx) {
      swap(arr[minIdx], arr[idx]);
      heapify(minIdx);
    }
  }

//  O(N)
  void buildHeap() {
    int lastParent = ((arr.size() - 1) - 1) / 2;

    for (int i = lastParent; i >= 0; i--) {
      heapify(i);
    }
  }

  void push(int val) {
    arr.push_back(val);

    int idx = arr.size() - 1;
    int par = (idx - 1) / 2;

    while (idx > 0 and arr[idx] < arr[par]) {
      swap(arr[idx], arr[par]);
      idx = par;
      par = (par - 1) / 2;
    }
  }

  void pop() {
    swap(arr[0], arr.back());
    arr.pop_back();
    heapify(0);
  }

  int top() {
    return arr[0];
  }

  int size() {
    return arr.size();
  }

  bool empty() {
    return arr.empty();
  }
};


int32_t main() {
  ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
  c_p_c();

  minHeap H;
  H.push(5);
  H.push(3);
  H.push(5);
  H.push(1);
  H.push(0);
  H.push(6);

  // cout << H.top();
  H.pop();

  // cout << H.top()<<endl;
  // cout << H.size();
  cout << H.empty();

  return 0;
}