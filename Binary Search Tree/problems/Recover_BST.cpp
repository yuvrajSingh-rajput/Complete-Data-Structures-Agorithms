class Solution {
    TreeNode* prev, *first, *middle, *last;
private: 
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);

        if(prev != NULL && (root->val < prev->val)){
            if(first == NULL) first = prev;
            else middle = last; 
            last = root;
        }

        prev = root;

        inorder(root->right);
    }
public:
    Solution(){
        this->prev = this->first = this->middle = this->last = NULL;
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val, last->val);
    }
};
