// LEETCODE - 103




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
    void reverse(vector<int> &level){
        int i = 0;
        int j = level.size() - 1;
        while (i < j){
            swap(level[i++], level[j--]);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue <TreeNode*> q;
        q.push(root);

        int leftToRight = true;

        while (!q.empty()){
            int s = q.size();
            vector<int> level;
            for (int i = 1; i <= s; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (!leftToRight) reverse(level);
            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};








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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue <TreeNode*> q;
        q.push(root);

        int leftToRight = true;

        while (!q.empty()){
            int s = q.size();
            vector<int> level(s);
            for (int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (leftToRight) ? i : s - 1 - i;
                level[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};