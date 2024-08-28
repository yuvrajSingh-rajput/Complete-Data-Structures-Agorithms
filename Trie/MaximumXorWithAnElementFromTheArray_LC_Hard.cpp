class Node {
public:
    Node* links[2];
    int mval = INT_MAX; 

    Node() {
        links[0] = links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertKey(int n) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            node->mval = min(node->mval, n); 
        }
    }

    int getMax(int n, int m) {
        Node* node = root;
        int maxVal = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            int key = 1 - bit;
            if (node->containsKey(key) && node->get(key)->mval <= m) {
                maxVal |= (1 << i); 
                node = node->get(key);
            } else if (node->containsKey(bit) && node->get(bit)->mval <= m) {
                node = node->get(bit);
            } else {
                return -1;
            }
        }
        return maxVal;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* trie = new Trie();
        for (int num : nums) {
            trie->insertKey(num);
        }
        vector<int> result;
        for (auto& query : queries) {
            int n = query[0], m = query[1];
            result.push_back(trie->getMax(n, m));
        }
        return result;
    }
};
