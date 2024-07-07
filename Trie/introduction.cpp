#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        this->flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        this->root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){

            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string& word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string &word){
        Node* node = root;

        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }

            node = node->get(word[i]);
        }

        return true;
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
