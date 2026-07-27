// LEETCODE - 222



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
    int countNodes(TreeNode* root) {
        int cnt = 0;
        if (root == NULL) return cnt;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int s = q.size();

            for (int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cnt += s;
        }

        return cnt;
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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if (lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeftHeight(TreeNode* node){
        int h = 0;
        while (node){
            h++;
            node = node->left;
        }
        return h;
    }

    int findRightHeight(TreeNode* node){
        int h = 0;
        while (node){
            h++;
            node = node->right;
        }
        return h;
    }
};