

//  Time: O(N^2) Space: O(1) Brute Force Iterating over strs
string longestCommonPrefix(vector<string>& strs) {

    int n = strs.size();
    string ans = "";
    int idx = 0, minSize = strs[0].size();

    for (int i = 0; i < n; i++) {
        int sz = strs[i].size();
        minSize = min(minSize, sz);
    }

    for (int idx = 0; idx < minSize; idx++) {

        char ch = strs[0][idx];
        bool flag = 1;
        for (int i = 0; i < n; i++) {

            if (strs[i][idx] != ch) {
                flag = 0;
                break;
            }
        }
        if (flag) ans.push_back(ch);
        else return ans;
    }

    return ans;
}


// -----------------------------------------------------------------------------

//  TIme: O(N*Logn)  Space: O(1) Using sorting the whole strs
string longestCommonPrefix(vector<string>& strs) {

    int n = strs.size();

    string ans;
    sort(strs.begin(), strs.end());

    // no need to compare all the strings
    // just compare first and last
    string first = strs[0];
    string last = strs[n - 1];

    for (int i = 0; i < min(first.size(), last.size()); i++) {
        if (first[i] != last[i]) break;

        ans.push_back(first[i]);
    }

    return ans;
}