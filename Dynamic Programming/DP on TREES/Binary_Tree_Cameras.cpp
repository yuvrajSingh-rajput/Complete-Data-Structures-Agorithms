class Solution {
    // Your states:
    // -1: I need a camera.
    //  0: I have a camera.
    //  1: I am covered (by a child's camera or I'm null).
    int postorder(TreeNode* root, int &ans){
        // Fix 1: The base case for recursion should handle NULL nodes.
        // A NULL node is considered "covered".
        if(!root) return 1;

        int left = postorder(root->left, ans);
        int right = postorder(root->right, ans);
        
        // If either child needs a camera, this node must place one.
        if(left == -1 || right == -1){
            ans++;
            return 0; // I have a camera.
        }
        
        // If either child has a camera, this node is now covered.
        if(left == 0 || right == 0) {
            return 1; // I am covered.
        }
        
        // If we reach here, both children are in state 1 (covered, but without a camera).
        // This means the current node is not monitored.
        return -1; // I need a camera.
    }
public:
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        
        // Fix 2: Check the final state of the root.
        // If the root needs a camera after the traversal, we must add one.
        if(postorder(root, ans) == -1){
            ans++;
        }
        
        return ans;
    }
};
