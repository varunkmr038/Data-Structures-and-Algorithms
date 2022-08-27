class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->val = val;
        this->key = key;
        next = NULL;
        prev = NULL;
    }
};

void removeHead(Node*& head, Node*& tail, int& curSize, unordered_map<int, Node*>& mp) {
    mp.erase(head->key);
    if (head == tail) {
        // delete head;
        head = NULL;
        tail = NULL;
    }
    else {
        head = head->next;
        if (head != NULL) {
            // delete head->prev;
            head->prev = NULL;
        }
    }
    curSize--;
}

class LRUCache {
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int curSize;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
        curSize = 0;
    }

// O(1)
    int get(int key) {
        if (!mp.count(key)) return -1;

        Node* cur = mp[key];
        int value = cur->val;

        if (cur->prev != NULL) cur->prev->next = cur->next;
        if (cur->next != NULL) cur->next->prev = cur->prev;

        if (head == cur) head = cur->next;
        if (tail == cur) tail = cur->prev;

        if (tail == NULL) {
            head = new Node(key, value);
            tail = head;
        }
        else {
            tail->next = new Node(key, value);
            tail->next->prev = tail;
            tail = tail->next;
        }
        mp[key] = tail;

        return mp[key]->val;
    }

// O(1)
    void put(int key, int value) {

        // so you get the nodeto be deleted
        // attach prev node to next before deleting
        if (mp.count(key)) {
            Node* cur = mp[key];

            if (cur->prev != NULL) cur->prev->next = cur->next;
            if (cur->next != NULL) cur->next->prev = cur->prev;

            if (head == cur) head = cur->next;
            if (tail == cur) tail = cur->prev;
            // delete cur;
        }

        // so key doesnt exist
        else {
            if (curSize == capacity) removeHead(head, tail, curSize, mp);
            curSize++;
        }


        if (tail == NULL) {
            head = new Node(key, value);
            tail = head;
        }
        else {
            tail->next = new Node(key, value);
            tail->next->prev = tail;
            tail = tail->next;
        }
        mp[key] = tail;
    }
};


