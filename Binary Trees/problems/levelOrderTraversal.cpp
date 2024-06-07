#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

//* take vector instead of multiset in case if we have to return vector<int> result;

class Solution {
public:
    vector<vector<int>> verticalTraversal(BinaryTreeNode<int>* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<BinaryTreeNode<int>*, pair<int, int>>> pendingNodes;
        pendingNodes.push({root, {0, 0}});
        while(!pendingNodes.empty()){
            BinaryTreeNode<int>* currNode = pendingNodes.front().first;
            int verticalHeight = pendingNodes.front().second.first;
            int horizontalDist = pendingNodes.front().second.second;
            pendingNodes.pop();
            mpp[horizontalDist][verticalHeight].insert(currNode->data);
            if(currNode->left){
                pendingNodes.push({currNode->left, {verticalHeight + 1, horizontalDist - 1}});
            }
            if(currNode->right){
                pendingNodes.push({currNode->right, {verticalHeight + 1, horizontalDist + 1}});
            }
        }
        for(auto &it: mpp){
            vector<int> temp;
            for(auto &ip : it.second){
                for(auto &i : ip.second){
                    temp.push_back(i);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};


int main(){
    return 0;
}