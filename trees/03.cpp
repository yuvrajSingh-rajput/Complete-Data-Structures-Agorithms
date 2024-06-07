//! Take input level-wise
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

TreeNode<int>* takeInputLevelwise(){
    int rootData;
    cout << "Enter the root data of the tree: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        int n;
        cout << "Enter the number of child of "<<front->data<<": ";
        cin >> n;
        for(int i = 0; i < n; i++){
            int c;
            cout << "Enter the "<<(i+1)<<"th child of "<<front->data<<": ";
            cin >> c;
            TreeNode<int>* child = new TreeNode<int>(c);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main(){
    
    return 0;
}