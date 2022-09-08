

int findMaxXor(vector<int>& nums, int val, int maxRange) {

    int ans = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > maxRange) break;

        ans = max(ans, nums[i] ^ val);
    }


    return ans;
}


//  TIme: O(Q*N)  Space: O(1) Brute force
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

    int n = nums.size();

    sort(nums.begin(), nums.end());
    vector<int> ans;

    for (int i = 0; i < queries.size(); i++) {
        int val = queries[i][0];
        int maxRange = queries[i][1];

        int mxXor = findMaxXor(nums, val, maxRange);
        ans.push_back(mxXor);
    }

    return ans;
}

// ----------------------------------------------------------------------------------------------------------------


class TrieNode {
public:
    TrieNode* left;  // 0 bit
    TrieNode* right; // 1 bit

    TrieNode() {
        left = NULL;
        right = NULL;
    }
};

class queryInfo {
public:

    int val;
    int maxRange;
    int idx;

    queryInfo(int val, int maxRange, int idx) {
        this->val = val;
        this->maxRange = maxRange;
        this->idx = idx;
    }
};


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


int findMaxXor(int value, TrieNode* root) {

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

static bool compare(queryInfo* a, queryInfo* b) {
    return a->maxRange < b->maxRange; // asc order of maxRange
}



//  TIme: O(Q*32 + Q*Logq)  Space: O(32) Using trie and sorting the nums and qeuries
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<queryInfo*> myQuery;

    for (int i = 0; i < queries.size(); i++) {
        myQuery.push_back(new queryInfo(queries[i][0], queries[i][1], i));
    }

    sort(myQuery.begin(), myQuery.end(), compare);

    TrieNode* root = new TrieNode();

    int sz = myQuery.size();

    vector<int> ans(sz);
    int idx = 0;

    for (int i = 0; i < myQuery.size(); i++) {
        int val = myQuery[i]->val;
        int maxRange = myQuery[i]->maxRange;
        int originalIdx = myQuery[i]->idx;

        while (idx < nums.size() and nums[idx] <= maxRange) {
            insert(nums[idx], root);
            idx++;
        }

        if (idx > 0) { // agar koi number within range hau
            int mxXor = findMaxXor(val, root);
            ans[originalIdx] = mxXor;
        }
        else ans[originalIdx] = -1;
    }

    return ans;
}