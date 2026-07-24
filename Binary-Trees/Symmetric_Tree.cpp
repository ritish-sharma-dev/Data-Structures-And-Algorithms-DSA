// LEETCODE - 101


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
    bool check(TreeNode* p, TreeNode* q){
        if (p == NULL && q == NULL) return true;

        if (p && q && p->val == q->val){
            bool x = check(p->left, q->right);
            if (!x) return false;
            bool y = check(p->right, q->left);
            if (!y) return false;
            return true;
        }

        return false;
    }


    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};