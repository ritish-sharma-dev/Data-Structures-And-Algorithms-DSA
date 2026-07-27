// LEETCODE - 236

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* root, vector<TreeNode*> &path, TreeNode* x){
        if (root == NULL) return false;

        path.push_back(root);
        if (root == x || f(root->left, path, x) || f(root->right, path, x)) return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath;
        vector<TreeNode*> qPath;

        f(root, pPath, p);
        f(root, qPath, q);

        int i = 0;
        int j = 0;
        while (i < pPath.size() && j < qPath.size() && pPath[i] == qPath[j]){
            i++, j++;
        }
        return pPath[i-1];
    }
};





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root;
        return left ? left : right;
    }
};