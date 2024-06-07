#include<bits/stdc++.h>
using namespace std;

//* Template
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(int data){
        this->data = data;
    }
};

//* takeInput function which returns the root node.
TreeNode<int>* takeInput(void){
    int data;
    cout << "Enter the data: ";
    cin >> data;
    TreeNode<int>* root = new TreeNode<int>(data);
    int n;
    cout << "Enter the number of the childrens of "<< root<< ": ";
    cin>> n;
    
    // recursive call
    for(int i = 0; i < n; i++){
        // this will return a pointer of the children node to the root node
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);    // push in the root.
    }
    return root;
}

// printing the tree
void printTree(TreeNode<int>* root){
    cout << root->data<<": ";
    for(int i = 0; i < root->children.size();i++){
        if(i != root->children.size() - 1){
            cout << root->children[i]->data <<", ";
        }else{
            root->children[i]->data;
        }
    }
    cout << endl;
    // recursive call.
    for(int i = 0; i < root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main(){
    
    return 0;
}