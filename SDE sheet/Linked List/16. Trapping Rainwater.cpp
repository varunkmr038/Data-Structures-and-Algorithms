//  Time: O(N^2) Space: O(1) BRute Force
int trap(vector<int>& height) {

  int n = height.size();
  int ans = 0;

  for (int i = 1; i < n - 1; i++) {
    int leftMax = height[i], rightMax = height[i];
    for (int j = i - 1; j >= 0; j--) leftMax = max(leftMax, height[j]);
    for (int j = i + 1; j < n; j++) rightMax = max(rightMax, height[j]);

    int containerHeight = min(leftMax, rightMax);
    ans += (containerHeight - height[i]);
  }

  return ans;

}


// ----------------------------------------------------------------------

//  Time: O(N) Space: O(N) 1d Dp
int trap(vector<int>& height) {

  int n = height.size();
  int ans = 0;

  //  To prestore the leftmax for each height
  vector<int> leftMax(n), rightMax(n);
  leftMax[0] = height[0];
  rightMax[n - 1] = height[n - 1];

  for (int i = 1; i < n; i++) {
    leftMax[i] = max(leftMax[i - 1], height[i]);
  }

  for (int i = n - 2; i >= 0; i--) {
    rightMax[i] = max(rightMax[i + 1], height[i]);
  }

  for (int i = 1; i < n - 1; i++) {
    int minHeight = min(leftMax[i], rightMax[i]);
    ans += (minHeight - height[i]);
  }
  return ans;
}


// ---------------------------------------------------------------------------------

//  Time: O(N) Space: O(1) Two Pointers
int trap(vector<int>& height) {

  int n = height.size();
  int ans = 0, left = 0, right = n - 1, leftMax = 0, rightMax = 0;

  while (left < right) {

//  iam making sure that there is someone >= my left values on right so i have to only think about left max
    if (height[left] < height[right]) {
      if (height[left] >= leftMax) leftMax = height[left];
      else ans += (leftMax - height[left]);
      left++;
    }
    else {
      if (height[right] >= rightMax) rightMax = height[right];
      else ans += (rightMax - height[right]);
      right--;
    }
  }
  return ans;

}


