#include<bits/stdc++.h>
//  TIme: O(N^2)  Space: O(n^2) Brute force
int countDistinctSubstrings(string &s)
{
    unordered_set<string> st;

    for (int i = 0; i < s.size(); i++) {

        string cur = "";
        for (int j = i; j < s.size(); j++) {
            cur += s[j];

            st.insert(cur);
        }
    }

    return st.size() + 1; // include emoty also
}

// -------------------------------------------------------------------------------------------------

