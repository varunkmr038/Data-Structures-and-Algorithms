

bool checkpalindrome(string str) {

    int n = str.size();

    int i = 0, j = n - 1;
    while (i < j) {

        if (str[i] != str[j]) return 0;

        i++; j--;
    }

    return 1;
}

//Time: O(N^3) Space: O(N) Brute force TLE
string longestPalindrome(string s) {

    int n = s.size();

    for (int len = n; len >= 1; len--) {

        for (int i = 0; (i + len - 1) < n; i++) {

            string str = s.substr(i, len);

            if (checkpalindrome(str)) return str;
        }

    }
    return s;
}

// --------------------------------------------------------------------------------------------



//Time: O(N^2) Space: O(N^2) using 2d dp
string longestPalindrome(string s) {

    int n = s.size(), mxlen = 1, start = 0;

    vector<vector<bool>> dp(n, vector<bool>(n, 1));

    for (int len = 2; len <= n; len++) {

        for (int i = 0; (i + len - 1) < n; i++) {

            int j = i + len - 1;
            bool p = 1;

            if (len > 2 and dp[i + 1][j - 1] != 1) p = 0;

            if (s[i] == s[j] and p == 1) {

                if (len > mxlen) {
                    mxlen = len;
                    start = i;
                }
            }
            else dp[i][j] = 0;
        }
    }
    return s.substr(start, mxlen);
}

//- -------------------------------------------------------------------------------------


//Time: O(N^2) Space: O(1) Expanding around centres
string longestPalindrome(string s) {

    int n = s.size(), mxlen = 1, start = 0;

    if (n == 0 or n == 1) return s;

    int left = 0, right = 0;

    // od len palindrome ek centre ke around expnad krna
    for (int i = 1; i < n - 1; i++) {

        left = i - 1;
        right = i + 1;
        int len = 1;

        while (left >= 0 and right < n and s[left] == s[right]) {
            left--;
            right++;
            len += 2;
        }

        if (len > mxlen) {
            mxlen = len;
            start = left + 1;
        }

    }

// even len palindrome 2 centres ke around expand krna
    for (int i = 0; i < n - 1; i++) {
        left = i;
        right = i + 1;
        int len = 0;

        while (left >= 0 and right < n and s[left] == s[right]) {
            left--;
            right++;
            len += 2;
        }

        if (len > mxlen) {
            mxlen = len;
            start = left + 1;
        }

    }
    return s.substr(start, mxlen);
}