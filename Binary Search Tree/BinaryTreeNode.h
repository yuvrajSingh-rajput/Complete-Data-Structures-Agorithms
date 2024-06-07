template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    // constructor
    BinaryTreeNode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    // destructor
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};


/*

    1. In BST, if we are standing on a node then every node in left of it are smaller than that standing node also every nodes on the right are greater than that standing node.

    2. if we want to print the elements of it, then for inorder traversal it prints in increasing order.

*/