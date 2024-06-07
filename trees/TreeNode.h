template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    // constructor.
    TreeNode(int data){
        this->data = data;
    }

    // destructor.
    ~TreeNode(){
        for(int i = 0; i < children.size(); i++){
            delete children[i];
        }
    }
};


//! PROPERTY_OF_DESTRUCTOR:
/*
    1. ONCE WE CALL THE "delete root", then first it will call the destructor first and do the things of that is written inside the destructor then it deletes that that node for which it is called.

    2. for an example here if we delete the root node then first it will delete the children's then after it deletes the root.

    does statement 2 not sounds like postorder traversal of a N-ary tree? , "YES" -> actually it can be deleted via postorder traversal too, we will see the code inn 01.cpp;
*/