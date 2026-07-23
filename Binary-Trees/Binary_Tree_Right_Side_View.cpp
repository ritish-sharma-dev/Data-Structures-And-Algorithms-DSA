// LEETCODE - 199



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

 // TC : O(n)
 // SC : O(w)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
            int size = q.size();
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);

            for (int i = 0; i < size; i++){
                node = q.front();
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
                q.pop();
            }
        }

        return ans;
    }
};