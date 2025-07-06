class Node {
public:
    int left_val, right_val, sum;
    Node(int left_val, int right_val, int sum) {
        this->left_val = left_val;  
        this->right_val = right_val; 
        this->sum = sum;
    }
};

class Solution {
    Node getMaxSumHelper(TreeNode* root, int& max_sum) {
        if (root == NULL)
            return Node(INT_MAX, INT_MIN, 0); 

        Node left = getMaxSumHelper(root->left, max_sum);
        Node right = getMaxSumHelper(root->right, max_sum);

        if (root->val > left.right_val && root->val < right.left_val) {
            int currSum = left.sum + right.sum + root->val;
            max_sum = max(max_sum, currSum);

            return Node(min(root->val, left.left_val), max(root->val, right.right_val), currSum);
        }

        return Node(INT_MIN, INT_MAX, INT_MIN);
    }

public:
    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        getMaxSumHelper(root, max_sum);
        return max_sum;
    }
};
