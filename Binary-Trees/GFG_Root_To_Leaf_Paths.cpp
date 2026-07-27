// GFG




/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

// TC : O(n)
// SC : O(h) maxheight of binarytree
class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> v;
    
    bool isLeaf(Node* root){
        return !(root->left) && !(root->right);
    }
    
    void findPaths(Node* root){
        if (root == NULL) return;
        
        v.push_back(root->data);
        if (isLeaf(root)) ans.push_back(v);
        else{
            findPaths(root->left);
            findPaths(root->right);
        }
        v.pop_back();
    }
    
    
    vector<vector<int>> paths(Node* root) {
        findPaths(root);
        
        return ans;
    }
};