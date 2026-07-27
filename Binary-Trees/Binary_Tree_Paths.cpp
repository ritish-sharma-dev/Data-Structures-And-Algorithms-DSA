// LEETCODE - 257


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
    bool isLeaf(TreeNode* node){
        return !(node->left) && !(node->right);
    }

    void findPaths(TreeNode* node, string s, vector<string> &ans){
        if (!node) return;

        s += to_string(node->val);

        if (isLeaf(node)){
            ans.push_back(s);
            return;
        }

        findPaths(node->left, s + "->", ans);
        findPaths(node->right, s + "->", ans);
;    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        findPaths(root, "", ans);

        return ans;
    }
};