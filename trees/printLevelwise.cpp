#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(int data){
        this->data = data;
    }
};

void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data<<": ";
        for(int i = 0; i < front->children.size(); i++){
            if(i != front->children.size()){
                cout << front->children[i]->data<<", ";
            }else{
                cout << front->children[i]->data;
            }
            cout<<endl;
            pendingNodes.push(front->children[i]);
        }
    }
}

int main(){
    
    return 0;
}