// LEETCODE - 111



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
    int minDepth(TreeNode* root) {
        // n is no of nodes and w is maxwidth
        // TC : O(n)
        // AS : O(w)
        int depth = 0;

        if (root == NULL) return depth;

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int s = q.size();
            
            for (int i = 1; i <= s; i++){
                TreeNode* node = q.front();
                q.pop();

                if ( !(node->left) && !(node->right) ) return ++depth;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }

        return depth;
    }
};