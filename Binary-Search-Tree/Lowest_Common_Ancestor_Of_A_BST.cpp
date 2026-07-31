// LEETCODE - 235




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
    void findPaths(TreeNode* root, TreeNode* query, vector<TreeNode*> &x){
        if (root == NULL) return;

        while(true){
            x.push_back(root);
            if (query->val < root->val){
                root = root->left;
            }else if (query->val > root->val){
                root = root->right;
            }else return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector <TreeNode*> pPath;
        vector <TreeNode*> qPath;

        findPaths(root, p, pPath);
        findPaths(root, q, qPath);

        int i = 0, j = 0;
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
// TC : O(n)
// SC : O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* x = root;
        TreeNode* y = root;
        TreeNode* LCA = root;

        while (true){
            if (x == y) LCA = x;
            if (x == p || x == q || y == p || y == q) break;

            if (p->val < x->val) x = x->left;
            else x = x->right;

            if (q->val < y->val) y = y->left;
            else y = y->right;
        }

        return LCA;
    }
};