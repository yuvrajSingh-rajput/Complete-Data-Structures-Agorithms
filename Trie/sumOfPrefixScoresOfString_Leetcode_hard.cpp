class Node {
public:
    Node* links[26];
    int count = 0; 

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void incrementCount() {
        this->count++;
    }

    int getCount() {
        return count;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }

    void insertWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incrementCount();  
        }
    }

    int findCommonPrefix(string word) {
        Node* node = root;
        int ans = 0;
        for (int i = 0; i < word.length(); i++) {
            node = node->get(word[i]);
            ans += node->getCount();
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *trie = new Trie();
        for (auto &str : words) {
            trie->insertWord(str);
        }
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            result.push_back(trie->findCommonPrefix(words[i]));
        }
        return result;
    }
};
