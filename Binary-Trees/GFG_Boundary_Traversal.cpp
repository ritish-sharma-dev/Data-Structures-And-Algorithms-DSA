// GFG - Tree Boundary Traversal




/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isLeaf(Node* root){
        return root->left == NULL && root->right == NULL;
    }
    
    void addLeftBoundary(Node* root, vector<int> &ans){
        Node* node = root->left;
        while (node){
            if (!isLeaf(node)) ans.push_back(node->data);
            if (node->left) node = node->left;
            else node = node->right;
        }
    }
    
    void addLeaves(Node* root, vector<int> &ans){
        if (root == NULL) return;
        if (isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
    
    void addRightBoundary(Node* root, vector<int> &ans){
        Node* node = root->right;
        stack<int> s;
        while (node){
            if (!isLeaf(node)) s.push(node->data);
            if (node->right) node = node->right;
            else node = node->left;
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);
        
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        
        return ans;
        
    }
};