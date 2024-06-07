#include "BinaryTreeNode.h"
class BST{
    private:

    BinaryTreeNode<int>* root;

    public:
    BST(){
        this->root = nullptr;
    }
    ~BST(){
        delete this->root;
    }
    private:
    //! REMOVE A NODE FROM BINARY SEARCH TREE.
    BinaryTreeNode<int>* deleteNodeHelper(BinaryTreeNode<int>*node, int data){
        if(node == nullptr){
            return nullptr;
        }
        if(data > node->data){
            node->right = deleteNodeHelper(node->right, data);
            return node;
        }else if(data < node->data){
            node->left = deleteNodeHelper(node->left, data);
            return node;
        }else{
            if(root->left == nullptr && root->right == nullptr){
                delete node;
                return nullptr;
            }else if(root->left == nullptr){
                BinaryTreeNode<int>* temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }else if(node -> right == nullptr){
                BinaryTreeNode<int>* temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left != nullptr){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteNodeHelper(node->right, rightMin);
                return node;
            }
        }
    }
    public:
    void deleteNode(int data){
        this->root = deleteNodeHelper(this->root, data);
    }
    //! INSERT A NODE IN BINARY SEARCH TREE.
    private:
    BinaryTreeNode<int>* insertNodeHelper(BinaryTreeNode<int>* node, int data){
        if(node == nullptr){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data <= node->data){
            node->left = insertNodeHelper(node->left, data);
        }else{
            node->right = insertNodeHelper(node->right, data);
        }
        return node;
    }
    public:
    void insertNode(int data){
        insertNodeHelper(root, data);
    }
    //! CHECK IF THE DATA TO BE SEARCHED IS PRESENT IN THE BST OR NOT!
    private:
    bool isDataHelper(BinaryTreeNode<int>*node, int data){
        if(node == nullptr){
            return false;
        }
        if(node->data == data){
            return true;
        }else if(data < root->data){
            return isDataHelper(node->left, data);
        }else{
            return isDataHelper(root->right, data);
        }
    }
    public:
    bool isData(int data){
        return isDataHelper(root, data);
    }
};