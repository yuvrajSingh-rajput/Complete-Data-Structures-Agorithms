class Solution {
    pair<int, int> solve(TreeNode* root){
        if(!root) return {0, 0};
        // {include, exclude}

        auto left = solve(root->left);
        auto right = solve(root->right);

        int take = root->val + left.second + right.second;

        int not_take = max(left.first, left.second) + max(right.first, right.second);

        return {take, not_take};
    }
public:
    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};
