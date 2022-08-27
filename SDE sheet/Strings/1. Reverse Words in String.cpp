
//  TIme: O(N)  Space: O(N) Simpe using loop
string reverseWords(string s) {

    int n = s.size();
    if (n == 1) return s;

    string cur;

    int i = n - 1;
    while (i >= 0) {
        while (i >= 0 and s[i] == ' ')  i--;

        string word;
        while (i >= 0 and s[i] != ' ')
            word.push_back(s[i--]);

        reverse(word.begin(), word.end());
        cur += word;
        cur.push_back(' ');
    }

    while (cur.back() == ' ')
        cur.pop_back();

    return cur;
}

// --------------------------------------------------------------------------------

" hello world  "


string reverseWords(string s) {

    int n = s.size();
    if (n == 1) return s;

    string cur;

    int i = n - 1;
    while (i >= 0) {
        while (i >= 0 and s[i] == ' ')  i--;

        string word;
        while (i >= 0 and s[i] != ' ')
            word.push_back(s[i--]);

        reverse(word.begin(), word.end());
        cur += word;
        cur.push_back(' ');
    }

    while (cur.back() == ' ')
        cur.pop_back();

    return cur;
}