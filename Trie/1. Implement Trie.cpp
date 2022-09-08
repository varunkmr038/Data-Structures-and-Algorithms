
class Node {
public:

    vector<Node*> next;
    int isEnd;

    Node() {
        next.resize(26);
        for (int i = 0; i < 26; i++) next[i] = NULL;
        isEnd = 0;
    }
};


class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {

        Node* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (cur->next[ch - 'a'] == NULL) {
                cur->next[ch - 'a'] = new Node();
            }
            cur = cur->next[ch - 'a'];
        }
        cur->isEnd++;
    }

    bool search(string word) {
        Node* cur = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (cur->next[ch - 'a'] == NULL) return false;
            cur = cur->next[ch - 'a'];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        Node* cur = root;

        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if (cur->next[ch - 'a'] == NULL) return false;
            cur = cur->next[ch - 'a'];
        }
        return true;
    }
};