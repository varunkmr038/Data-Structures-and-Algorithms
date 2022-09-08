
class Node {

public:

    vector<Node*> next;
    int isEnd;
    int cntPref;

    Node() {
        next.resize(26);
        for (int i = 0; i < 26; i++) next[i] = NULL;
        isEnd = 0;
        cntPref = 0;
    }
};

class Trie {
    Node* root;

public:

    Trie() {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (cur->next[ch - 'a'] == NULL) {
                cur->next[ch - 'a'] = new Node();
            }
            cur = cur->next[ch - 'a'];
            cur->cntPref++;
        }
        cur->isEnd++;
    }

    int countWordsEqualTo(string &word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (cur->next[ch - 'a'] == NULL) return 0;
            cur = cur->next[ch - 'a'];
        }
        return cur->isEnd;
    }

    int countWordsStartingWith(string &word) {
        Node* cur = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (cur->next[ch - 'a'] == NULL) return 0;
            cur = cur->next[ch - 'a'];
        }
        return cur->cntPref;
    }

    void erase(string &word) {
        Node* cur = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            cur = cur->next[ch - 'a'];
            cur->cntPref--;
        }
        cur->isEnd--;
    }

};