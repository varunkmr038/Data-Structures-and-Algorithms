
//  TIme: O(N*N)  Space: O(2*N) Using map
int celebrity(vector<vector<int> >& m, int n)
{
    int ans = -1;

//   person ->  { person fame , whom person knows }
    unordered_map<int, pair<int, int>> people;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == 1) {
                // fame of jth person inc
                people[j].first++;
                people[i].second++;
            }
        }
    }

    // jin jin people ki fame == n-1 hai just cgheck krli they dont know anyone
    for (auto cur : people) {
        int fame = cur.second.first;
        if (fame < n - 1) continue;

        int curPerson = cur.first;
        int whomIKnow = cur.second.second;

        if (fame == n - 1 and whomIKnow == 0) {
            ans = curPerson;
            break;
        }

    }

    return ans;
}


// ---------------------------------------------------------------------------------

//  TIme: O(N)  Space: O(N) Using stack
int celebrity(vector<vector<int> >& m, int n)
{
    int ans = -1;

    // sbko stack me push krdo
    // phir shuru ke do uthao or dekho kya wo celebrity bn kste hai ya nhi
    // agar a -> b  ko janta hai  a can never be celebrity so push b in stack
    // agar dono ek dusre ko jante hau dont push anything

    stack<int> st;

    for (int i = 0; i < n; i++) st.push(i);

    while (st.size() > 1) {

        int p1 = st.top();
        st.pop();
        int p2 = st.top();
        st.pop();

        if (m[p1][p2] == 0 and m[p2][p1] == 1) st.push(p1); // if p2 -knows > p1 but p1 doesnt
        else if (m[p2][p1] == 0 and m[p1][p2] == 1) st.push(p2);

    }

    if (st.empty()) return -1;
    int canBeCeleb = st.top();
    bool isCeleb = 1;

    for (int i = 0; i < n; i++) {
        if (i != canBeCeleb)
            if (m[canBeCeleb][i] == 1) isCeleb = 0;
    }

    for (int i = 0; i < n; i++) {
        if (i != canBeCeleb)
            if (m[i][canBeCeleb] == 0) isCeleb = 0;
    }

    if (isCeleb) ans = canBeCeleb;

    return ans;
}