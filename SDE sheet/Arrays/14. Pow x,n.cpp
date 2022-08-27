// Time: O(Logn) Space: O(1) Using Inbuilt Pow
double myPow(double x, int n) {
  double ans = 0;

  ans = pow(x, n);

  return ans;
}

/// --------------------------------------------------------------------


double solve(double x, int n) {

  if (n == 0) return 1;
  if (n == 1) return x;

  if (n % 2 == 0) return solve(x * x, n / 2);
  else return solve(x * x, n / 2) * x;
}

// Time: O(Logn) Space: O(Logn) Using Recursion
double myPow(double x, int n) {
  double ans = 0;

  ans = solve(x, n);
  if (n < 0) ans = 1.0 / ans;

  return ans;
}