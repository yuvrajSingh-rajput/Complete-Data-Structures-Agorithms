#include "bits/stdc++.h"
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        queue<BinaryTreeNode<int> *> pendingNodes;
        pendingNodes.push(root);

        bool reachedEnd = false;

        while (!pendingNodes.empty())
        {
            TreeNode *node = pendingNodes.front();
            pendingNodes.pop();

            // If we've reached a null node, mark that we've reached the end of the complete part
            if (node == nullptr)
            {
                reachedEnd = true;
            }
            else
            {
                // If we've reached the end and we encounter a non-null node, it's not a complete tree
                if (reachedEnd)
                    return false;

                // Add left and right children to the queue
                pendingNodes.push(node->left);
                pendingNodes.push(node->right);
            }
        }

        // If we reach here, the tree satisfies the completeness property
        return true;
    }
};