// LEETCODE - 863



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
// SC : O(n)
class Solution {
public:
    void markParents(TreeNode* root, unordered_map <TreeNode*, TreeNode*> &mp){
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int s = q.size();

            for (int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();

                if (node->left){
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if (node->right){
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*, TreeNode*> mp;
        markParents(root, mp);

        unordered_map <TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        int dist = 0;

        while (dist != k){
            int s = q.size();

            for (int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();

                visited[node] = true;

                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]){
                    q.push(node->right);
                }
                if (mp[node] && !visited[mp[node]]){
                    q.push(mp[node]);
                }
            }

            dist++;
        }

        vector<int> ans;
        while (!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};