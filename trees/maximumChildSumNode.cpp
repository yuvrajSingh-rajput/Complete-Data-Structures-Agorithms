// CPP program to find the node whose children
// and node sum is maximum.
#include <bits/stdc++.h>
using namespace std;

// Structure of a node of an n-ary tree
struct Node {
	int key;
	vector<Node*> child;
};

// Utility function to create a new tree node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	return temp;
}

// Helper function to find the node
void maxSumUtil(Node* root, Node** resNode, int* maxsum)
{
	// Base Case
	if (root == NULL)
		return;

	// curr contains the sum of the root and 
	// its children
	int currsum = root->key;

	// total no of children
	int count = root->child.size();

	// for every child call recursively
	for (int i = 0; i < count; i++) {
		currsum += root->child[i]->key;
		maxSumUtil(root->child[i], resNode, maxsum);
	}

	// if curr is greater than sum, update it
	if (currsum > *maxsum) {

		// resultant node
		*resNode = root;
		*maxsum = currsum;
	}
	return;
}

// Function to find the node having max sum of 
// children and node
int maxSum(Node* root)
{
	// resultant node with max sum of children
	// and node
	Node* resNode;

	// sum of node and its children
	int maxsum = 0;

	maxSumUtil(root, &resNode, &maxsum);

	// return the key of resultant node
	return resNode->key;
}

// Driver program
int main()
{
	/* Let us create below tree
	*		    1
	*		 /  |  \
	*	   2    3    4
	*	 / \  / | \   \
	*	5   6 7 8  9  10
	*/

	Node* root = newNode(1);
	(root->child).push_back(newNode(2));
	(root->child).push_back(newNode(3));
	(root->child).push_back(newNode(4));
	(root->child[0]->child).push_back(newNode(5));
	(root->child[0]->child).push_back(newNode(6));
	(root->child[2]->child).push_back(newNode(5));
	(root->child[2]->child).push_back(newNode(6));
	(root->child[2]->child).push_back(newNode(6));

	cout << maxSum(root) << endl;

	return 0;
}







































// #include <iostream>
// #include <vector>
// #include <limits>
// using namespace std;

// template <typename T>
// class TreeNode {
// public:
//     T data;
//     vector<TreeNode<T>*> children;

//     TreeNode(T val) : data(val) {}
// };

// template <typename T>
// class MaxChildSumNodeResult {
// public:
//     TreeNode<T>* node;
//     T sum;

//     MaxChildSumNodeResult(TreeNode<T>* n, T s) : node(n), sum(s) {}
// };

// template <typename T>
// MaxChildSumNodeResult<T> maxChildSumNodeHelper(TreeNode<T>* root) {
//     if (root == nullptr) {
//         return MaxChildSumNodeResult<T>(nullptr, numeric_limits<T>::min());
//     }

//     T sum = root->data;  // Include the data of the current node
//     for(int i = 0; i < root->children.size(); i++){
//         sum += root->children[i]->data;
//     }

//     for (TreeNode<T>* child : root->children) {
//         MaxChildSumNodeResult<T> childResult = maxChildSumNodeHelper(child);

//         sum += childResult.sum;  // Update the sum with child's sum
//     }

//     return MaxChildSumNodeResult<T>(root, sum);
// }

// template <typename T>
// TreeNode<T>* maxChildSumNode(TreeNode<T>* root) {
//     return maxChildSumNodeHelper(root).node;
// }

// int main() {
//     // Example usage:
//     // Construct a sample tree
//     TreeNode<int>* root = new TreeNode<int>(1);
//     root->children.push_back(new TreeNode<int>(2));
//     root->children.push_back(new TreeNode<int>(3));
//     root->children[0]->children.push_back(new TreeNode<int>(4));
//     root->children[0]->children.push_back(new TreeNode<int>(5));
//     root->children[1]->children.push_back(new TreeNode<int>(6));

//     // Find the node with the maximum sum of its child nodes' data
//     TreeNode<int>* result = maxChildSumNode(root);

//     // Output the result
//     cout << "Node with maximum sum of child nodes' data: " << result->data << endl;

//     // Don't forget to free the allocated memory

//     return 0;
// }
