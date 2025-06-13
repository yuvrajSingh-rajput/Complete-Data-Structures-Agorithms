class NodeValue {
public:
    int maxVal, minVal, maxSize;

    NodeValue(int minVal, int maxVal, int maxSize) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTHelper(Node* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);

        if (left.maxVal < root->data && root->data < right.minVal) {
            return NodeValue(
                min(left.minVal, root->data),
                max(right.maxVal, root->data),
                left.maxSize + right.maxSize + 1
            );
        }

        // If not a BST, return invalid range and max size found so far
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(Node* root) {
        return largestBSTHelper(root).maxSize;
    }
};
