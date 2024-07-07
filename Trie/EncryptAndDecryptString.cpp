class Node {
public:
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
    }

    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }

    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    Node* get(char ch) { return links[ch - 'a']; }

    void setEnd() { this->flag = true; }

    bool isEnd() { return this->flag; }
};

class Trie {
    Node* root;

public:
    Trie() { this->root = new Node(); }

    ~Trie() { deleteTrie(root); }

    void insert(string& word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string& word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    Node* getRoot() {
        return root;
    }

private:
    void deleteTrie(Node* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->links[i]) {
                deleteTrie(node->links[i]);
            }
        }
        delete node;
    }
};

class Encrypter {
    vector<char> keys;
    vector<string> values;
    Trie* root;
    unordered_map<char, int> mpp;
    map<string, vector<int>> freq;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        this->root = new Trie();
        this->keys = keys;
        this->values = values;

        for (int i = 0; i < keys.size(); i++)
            mpp[keys[i]] = i;

        for (int i = 0; i < values.size(); i++)
            freq[values[i]].push_back(i);

        for (int i = 0; i < dictionary.size(); i++)
            root->insert(dictionary[i]);
    }

    ~Encrypter() {
        delete root;
    }

    string encrypt(string word1) {
        string result = "";
        for (int i = 0; i < word1.length(); i++) {
            if (mpp.find(word1[i]) == mpp.end())
                return "";
            int index = mpp[word1[i]];
            result.append(values[index]);
        }
        return result;
    }

    int decrypt(string word2) {
        vector<Node*> currentMatch;
        currentMatch.push_back(root->getRoot());

        for (int i = 0; i < word2.length(); i += 2) {
            string k = word2.substr(i, 2);
            vector<int> idx = freq[k];
            vector<Node*> nextMatch;

            for (int j : idx) {
                char ch = keys[j];

                for (Node* temp : currentMatch) {
                    if (temp->containsKey(ch)) {
                        nextMatch.push_back(temp->get(ch));
                    }
                }
            }

            if (nextMatch.empty())
                return 0;

            currentMatch = nextMatch;
        }

        int count = 0;
        for (Node* node : currentMatch) {
            if (node->isEnd()) count++;
        }

        return count;
    }
};
