
class MyQueue {

    stack<int> s1, s2;

public:
    MyQueue() {

    }

    // O(N)
    void push(int x) {

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

    }

    // O(1)
    int pop() {
        int val = s1.top();
        s1.pop();

        return val;
    }

    // O(1)
    int peek() {
        return s1.top();
    }

    // O(1)
    bool empty() {
        return s1.empty();
    }
};


// ---------------------------------------------------------------------

//O(1) amortized Time complexity  O(2N) Space
class MyQueue {

    stack<int> input, output;

public:
    MyQueue() {

    }

    // O(1)
    void push(int x) {
        input.push(x);
    }

    // O(1)  // ye pop or top jo hai kbhi kbhi ho rhe hai
    // most of the cases me O(1) rhengi
    int pop() {
        if (output.size() > 0) {
            int val = output.top();
            output.pop();
            return val;
        }
        else if (input.size() > 0) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }

            int val = output.top();
            output.pop();
            return val;
        }
        else return -1;
    }

    // O(1)
    int peek() {
        if (output.size() > 0) return output.top();

        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }

        return output.top();
    }

    // O(1)
    bool empty() {
        return input.empty() and output.empty();
    }
};


