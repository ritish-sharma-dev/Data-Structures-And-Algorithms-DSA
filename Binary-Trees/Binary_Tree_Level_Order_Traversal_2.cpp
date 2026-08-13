// LEETCODE - 107


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
    void reverse(vector<vector<int>> &ans){
        int i = 0;
        int j = ans.size() - 1;
        while (i < j){
            swap(ans[i++], ans[j--]);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int s = q.size();

            vector<int> v;
            for (int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(v);
        }

        reverse(ans);

        return ans;
    }
};