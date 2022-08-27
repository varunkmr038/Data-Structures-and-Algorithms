// Time : O(N) Space : O(N)
bool isValid(string x) {

    int n = x.size();

    stack<char> s;

    for (int i = 0; i < n; i++) {

        if (x[i] == '{' or x[i] == '[' or x[i] == '(') s.push(x[i]);

        else {

            if (s.empty()) return 0;

            if (x[i] == '}' and s.top() != '{') return 0;
            if (x[i] == ']' and s.top() != '[') return 0;
            if (x[i] == ')' and s.top() != '(') return 0;

            s.pop();
        }
    }

    return s.empty();

}