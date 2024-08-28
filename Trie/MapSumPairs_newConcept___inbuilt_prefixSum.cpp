class Node {
public:
    Node* links[26];
    int score = 0;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void incrementScore(int delta) {
        this->score += delta;
    }

    int getScore() {
        return score;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }

    void insertWord(const string& word, int val, const unordered_map<string, int>& map) {
        Node* node = root;
        int delta = val - (map.count(word) ? map.at(word) : 0); 
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->incrementScore(delta); 
        }
    }

    int netPrefixScore(const std::string& word) {
        Node* node = root;
        int ans = 0;
        for (char ch : word) {
            node = node->get(ch);
            if (node == NULL) return 0;
            ans = node->getScore();
        }
        return ans;
    }
};

class MapSum {
    Trie* trie;
    unordered_map<string, int> map;
public:
    MapSum() {
        this->trie = new Trie();
    }
    
    void insert(string key, int val) {
        trie->insertWord(key, val, map);
        map[key] = val; 
    }
    
    int sum(string prefix) {
        return trie->netPrefixScore(prefix);
    }
};
