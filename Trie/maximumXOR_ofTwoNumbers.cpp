class Node {
public:
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
    Node* root;
public: 
    Trie() {
        root = new Node();
    }

    void insertBits(int n) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int n) {
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            int oppositeBit = 1 - bit;
            if(node->containsKey(oppositeBit)) {
                maxNum |= (1 << i);  
                node = node->get(oppositeBit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(int num : nums) {
            trie->insertBits(num);
        }
        int maxNum = 0;
        for(int num : nums) {
            maxNum = max(maxNum, trie->getMax(num));
        }
        return maxNum;
    }
};
