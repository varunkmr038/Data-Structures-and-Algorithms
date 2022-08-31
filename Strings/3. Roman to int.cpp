
// Time: O(N) Space: O(N) Using hashing
int romanToInt(string s) {

    int n = s.size(), ans = 0;

    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    ans = mp[s[n - 1]];

    for (int i = n - 2; i >= 0; i--) {

        //  IX case
        if (mp[s[i + 1]] > mp[s[i]])
            ans -= mp[s[i]];

        //  XV case
        else ans += mp[s[i]];

    }

    return ans;

}
