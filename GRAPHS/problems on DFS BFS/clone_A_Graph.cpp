class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        unordered_map<Node*, Node*> cloned;
        return cloneGraphHelper(node, cloned);
    }
    
private:
    Node* cloneGraphHelper(Node* node, unordered_map<Node*, Node*>& cloned) {
        if (cloned.find(node) != cloned.end()) {
            return cloned[node];
        }
        Node* newNode = new Node(node->val);
        cloned[node] = newNode;  
        
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraphHelper(neighbor, cloned));
        }
        
        return newNode;
    }
};
