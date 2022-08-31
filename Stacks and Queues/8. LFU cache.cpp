
class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    int cnt;

    Node(int key, int val) {
        this->val = val;
        this->key = key;
        next = NULL;
        prev = NULL;
        cnt = 1;
    }
};




class LFUCache {

    int capacity;
    //  1 -> head, tail
    unordered_map<int, pair<Node*, Node*>> freq; // for freq
    unordered_map<int, Node*> mp; // key - cur
    int curSize;
    int leastFreq;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
        leastFreq = 1;
    }

    int get(int key) {
        if (capacity == 0 or !mp.count(key)) return -1;

        Node* cur = mp[key];

        deleteNodeFromFreq(cur); // deletes from prev freq

        insertNodeFreq(cur); // insert at new freq

        return cur->val;
    }

    // O(1)
    void put(int key, int value) {

        if (capacity == 0) return ;

        Node* cur;

        // key exists
        if (mp.count(key)) {
            cur = mp[key];
            cur->val = value;
            deleteNodeFromFreq(cur);
        }


        // so key doesnt exist
        else {
            if (curSize == capacity) removeLeastFreq();

            leastFreq = 1; // nayi node hau to mai hi least hu
            cur = new Node(key, value);
            curSize++;
        }

        insertNodeFreq(cur); // inseert node at freq
        mp[key] = cur;
    }


    void insertNodeFreq(Node* cur) {
        int f = cur->cnt;

        // cur freq pe pehle se koi head tail hai
        if (freq.count(f)) {
            Node* head = freq[f].first;
            Node* tail = freq[f].second;
            tail->next = cur;
            cur->prev = tail;
            tail = cur;

            freq[f] = {head, tail};
        }
        else {
            freq[f] = {cur, cur}; // mai hi head mai hi tail
        }
    }


    void removeLeastFreq() {
        Node* head = freq[leastFreq].first;
        Node* tail = freq[leastFreq].second;

        mp.erase(head->key);

        if (head == tail) freq.erase(leastFreq);
        else freq[leastFreq] = {head->next, tail};
        curSize--;
    }


    void deleteNodeFromFreq(Node* cur) {
        Node* head = freq[cur->cnt].first;
        Node* tail = freq[cur->cnt].second;

        if (head == cur and tail == cur) {
            freq.erase(cur->cnt);
            if (cur->cnt == leastFreq) leastFreq++;
        }

        else {
            if (cur->prev != NULL) cur->prev->next = cur->next;
            if (cur->next != NULL) cur->next->prev = cur->prev;

            if (head == cur) head = cur->next;
            else if (tail == cur) tail = cur->prev;

            cur->prev = NULL;
            cur->next = NULL;

            freq[cur->cnt] = {head, tail};// update head and tail
        }
        cur->cnt = cur->cnt + 1;
    }
};
