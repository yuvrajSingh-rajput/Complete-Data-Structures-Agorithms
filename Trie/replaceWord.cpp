#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        this->flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }

    ~Trie() {
        deleteTrie(root);
    }

    void insert(const string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    string replaced(const string &word) {
        string result = "";
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])) return word;
            result.push_back(word[i]);
            node = node->get(word[i]);

            if(node->isEnd()) break;
        }
        return result;
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

class Solution {
public:
    string replaceWords(vector<string>& dictionary, const string& sentence) {
        if (dictionary.empty()) return "";
        string result = "", word;
        istringstream iss(sentence);
        Trie root;

        for (const string& dictWord : dictionary) {
            root.insert(dictWord);
        }

        while (iss >> word) {
            string replacedWord = root.replaced(word);
            result.append(replacedWord);
            result.push_back(' ');
        }
        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};

signed main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        cin.tie(nullptr);
        auto _clock_start = chrono::high_resolution_clock::now();
    #endif

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}
