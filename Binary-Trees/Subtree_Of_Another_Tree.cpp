// LEETCODE - 572



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
    bool check(TreeNode* node1, TreeNode* node2){
        if (!node1 && !node2) return true;

        if (node1 && node2 && node1->val == node2->val){
            if (check(node1->left, node2->left) && check(node1->right, node2->right) ){
                return true;
            }
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int s = q.size();

            for (int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();

                if (node->val == subRoot->val && check(node, subRoot)) {
                    return true;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return false;
    }
};