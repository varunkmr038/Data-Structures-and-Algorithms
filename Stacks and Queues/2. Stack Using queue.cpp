class MyStack {

    queue<int> q1, q2;

public:
    MyStack() {

    }

    void push(int x) {

        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();

        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

// ---------------------------------------------------------------------------

class MyStack {

    queue<int> q;

public:
    MyStack() {

    }

    void push(int x) {

        q.push(x);
        int sz = q.size() - 1;

        while (sz--) {
            int val = q.front();
            q.pop();
            q.push(val);
        }

    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};



