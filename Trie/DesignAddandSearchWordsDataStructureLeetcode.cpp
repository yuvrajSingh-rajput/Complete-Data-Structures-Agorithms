class Node {
public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    // <<<<<<<<<<<---------search recursively--------->>>>>>>>>>>>>>>
    bool searchWord(string word, int index, Node* node) {
        if (index == word.size()) {
            return node->isEnd();
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] && searchWord(word, index + 1, node->links[i])) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->containsKey(ch)) {
                return searchWord(word, index + 1, node->get(ch));
            } else {
                return false;
            }
        }
    }

    bool searchWord(string word) {
        return searchWord(word, 0, root);
    }
};

class WordDictionary {
    Trie* trie;
public:
    WordDictionary() {
        trie = new Trie();
    }

    void addWord(string word) {
        trie->insertWord(word);
    }

    bool search(string word) {
        return trie->searchWord(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
