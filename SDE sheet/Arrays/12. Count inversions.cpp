void merge(long long a[], long long s, long long mid, long long e, long long int& ans) {

  long long temp[e - s + 1];

  long long i = s, j = mid + 1, k = 0;
  long long int numLessThan = 0;

  while (i <= mid and j <= e) {
    if (a[i] < a[j]) {
      temp[k++] = a[i++];
      ans += numLessThan;
    }
    else {
      temp[k++] = a[j++];
      numLessThan++;
    }
  }

  while (i <= mid) {
    temp[k++] = a[i++];
    ans += numLessThan;
  }

  while (j <= e) temp[k++] = a[j++];

  k = 0;
  for (int i = s; i <= e; i++) {
    a[i] = temp[k++];
  }
}

//Function to mergesort the array, which uses divide and conquer algorithm
//on left and right halves of array for mergesort operation.
void mergeSort(long long a[], long long s, long long e, long long int& ans)
{
  if (s >= e) return;

  long long mid = (s + e) / 2;

  mergeSort(a, s, mid, ans);
  mergeSort(a, mid + 1, e, ans);

  merge(a, s, mid, e, ans);
}

// TIme: O(N*Logn) Space: O(Logn + N) Using merge sort
long long int inversionCount(long long arr[], long long N)
{
  long long int ans = 0;
  mergeSort(arr, 0, N - 1, ans);

  return ans;
}
