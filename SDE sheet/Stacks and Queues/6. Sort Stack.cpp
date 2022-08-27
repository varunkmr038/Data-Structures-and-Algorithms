
//  TIme: O(N*N) Space: O(N) Recursive insertion sort highest on top
void SortedStack :: sort()
{
    if (s.empty()) return;

    int val = s.top();
    s.pop();

    sort();

    // aate samay cur val ko stack me sorted state me daaalna hai
    insertVal(s, val);
}

// put the val at sorted place in stack
int insertVal(stack<int>& s, int val) {

    if (s.empty()) {
        s.push(val);
        return ;
    }

    // iska mtlb val top se neeche ayengi to recurse kro or
    if (s.top() >= val) {
        int x = s.top();
        s.pop();
        insertVal(s, val);
        s.push(x);
    }
    // yhi position pe rkhna hai
    else {
        s.push(val);
        return;
    }
}