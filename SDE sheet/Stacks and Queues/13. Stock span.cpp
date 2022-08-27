

//  Time: O(n^2) Space: O(N) Brute forces
class StockSpanner {

    vector<int> stocks;

public:
    StockSpanner() {

    }

    int next(int price) {

        int ans = 1;
        for (int j = stocks.size() - 1; j >= 0; j--) {
            if (stocks[j] > price) break;
            ans++;
        }
        stocks.push_back(price);
        return ans;
    }
};

// -------------------------------------------------------------------------




//  Time: O(1) Space: O(2*N) Using monotonic stack
class StockSpanner {

    stack<int> st;
    vector<int> stocks;
    int idx;

public:
    StockSpanner() {
        idx = 0;
    }

    int next(int price) {

        // mai kitno se bada hu unka kaam nhi hai ab
        // kyuki agar mere se chota koi aata hau wo to mujhe hi nhi tod payega
        // or ager bada ata hau to wo un sb ko to tod dega jinko mai tod chuka hu
        // or check sirf mere se bade pe lgega
        while (!st.empty() and stocks[st.top()] <= price) st.pop();

        int ans = 0;
        if (st.empty()) { // mtlb aapne sbko tod diya
            ans = idx + 1;
        }
        else ans = idx - st.top() ;

        st.push(idx);
        stocks.push_back(price);
        idx++;
        return ans;
    }
};