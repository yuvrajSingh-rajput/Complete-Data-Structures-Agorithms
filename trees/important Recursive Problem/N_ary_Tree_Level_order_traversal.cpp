#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;

    if (root == nullptr) {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelValues;

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            levelValues.push_back(current->val);

            for (Node* child : current->children) {
                if (child != nullptr) {
                    q.push(child);
                }
            }
        }

        result.push_back(levelValues);
    }

    return result;
}
};

int main(){
    
    return 0;
}