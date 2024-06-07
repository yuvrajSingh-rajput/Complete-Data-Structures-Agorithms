

void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        flatten(root->left);
        flatten(root->right);
        if(root->left != NULL){
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode* curr = root->right;
            while(curr->right != NULL){
                curr = curr->right;
            }
            curr->right = temp;
        }
    }