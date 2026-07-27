// LEETCODE - 872




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* node, vector<int> &z){
        if (!node) return;

        if (!node->left && !node->right) {
            z.push_back(node->val);
            return;
        }
        traverse(node->left, z);
        traverse(node->right, z);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> x;
        vector<int> y;

        traverse(root1, x);
        traverse(root2, y);

        return x == y;
    }
};