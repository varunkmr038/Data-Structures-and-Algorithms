class TrieNode {
public:
    TrieNode* left;  // 0 bit
    TrieNode* right; // 1 bit

    TrieNode() {
        left = NULL;
        right = NULL;
    }
};


class Solution {
public:
    void insert(int val, TrieNode* root) {

        TrieNode* cur = root;

        for (int i = 31; i >= 0; i--) {
            int curBit = (val >> i) & 1;

            // I will go to left
            if (curBit == 0) {
                if (cur->left == NULL) cur->left = new TrieNode();
                cur = cur->left;
            }

            else {
                if (cur->right == NULL) cur->right = new TrieNode();
                cur = cur->right;
            }
        }
    }


    int solve(int value, TrieNode* root) {

        TrieNode* cur = root;

        int numberToFind = 0;

        for (int i = 31; i >= 0; i--) {
            int curBit = (value >> i) & 1;

            // I have to maximise the xor so
            // I will try to go right for  1 bit
            if (curBit == 0) {

                if (cur->right == NULL) cur = cur->left; // then no way you have to go left for 0 bit
                else {
                    cur = cur->right;
                    numberToFind += 1 << i;
                }
            }
            // try to go left for 0 bit
            else {

                if (cur->left == NULL) {
                    cur = cur->right;
                }

                else {
                    numberToFind += 1 << i;
                    cur = cur->left;
                }
            }
        }

        return numberToFind;
    }


// Time: O(N) Space: O(1) Trie based Storing Number 32 bits in trie
    int findMaximumXOR(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        TrieNode* root = new TrieNode();

        for (int i = 0; i < n; i++) {
            insert(nums[i], root);
        }

        for (int i = 0; i < n; i++) {

            int curAns = solve(nums[i], root);
            ans = max(ans, curAns);
        }

        return ans;
    }