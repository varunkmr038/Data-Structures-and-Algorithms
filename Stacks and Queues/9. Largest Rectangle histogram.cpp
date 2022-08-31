//  Time: O(N) Space: O(N) Using Stack
int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();
    int ans = 0;
    stack<int> s;

    for (int i = 0; i < n; ) {

        if (s.empty() or heights[i] >= heights[s.top()]) {
            s.push(i);
            i++;
            continue;
        }

        //  Now if Im here then the value is acting as next smaller for my stack top

        int curHeight = heights[s.top()];
        s.pop();
        int curArea = 0;
        int nextSmaller = i;

        if (s.empty()) {   // this means I have no prevsmaller

            int width = nextSmaller;
            curArea = curHeight * width;
        }

        else {
            int prevSmaller = s.top();
            int width = nextSmaller - prevSmaller - 1;
            curArea = width * curHeight;
        }

        ans = max(ans, curArea);
    }


    //  Now for those left considering nextsmaller as N
    while (!s.empty()) {
        int curHeight = heights[s.top()];
        s.pop();
        int curArea = 0;

        if (s.empty()) {
            curArea = n * curHeight;
        }

        else {
            int prevSmaller = s.top();
            curArea = (n - prevSmaller - 1) * curHeight;
        }


        ans = max(ans, curArea);

    }


    return ans;

}