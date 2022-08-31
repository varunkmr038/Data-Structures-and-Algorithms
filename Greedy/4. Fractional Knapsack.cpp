
static bool compare(Item a, Item b) {
  return (1.0 * a.value / a.weight) > (1.0 * b.value / b.weight);
}


//  Time: O(N*Logn) Space: O(1)
double fractionalKnapsack(int W, Item arr[], int n)
{
  double ans = 0;

  sort(arr, arr + n, compare);
  int curW = 0;

  for (int i = 0; i < n; i++) {

    if (curW + arr[i].weight > W) {
      ans += (1.0 * arr[i].value / arr[i].weight) * (W - curW);
      break;
    }

    curW += arr[i].weight;
    ans += arr[i].value;

  }
  return ans;

}


