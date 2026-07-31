// LEETCODE - 98




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
    long long findLeftMax(TreeNode* node){
        if (node == NULL) return LLONG_MIN;

        while (node->right != NULL){
            node = node->right;
        }
        return node->val;
    }

    long long findRightMin(TreeNode* node){
        if (node == NULL) return LLONG_MAX;

        while (node->left != NULL){
            node = node->left;
        }
        return node->val;
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        long long leftMax = findLeftMax(root->left);
        long long rightMin = findRightMin(root->right);

        if (leftMax < root->val && rightMin > root->val){
            if (isValidBST(root->left) && isValidBST(root->right)) {
                return true;
            }
        }

        return false;
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
    bool check(TreeNode* root, long long minRange, long long maxRange){
        if (root == NULL) return true;

        if (root->val > minRange && root->val < maxRange){
            if (check(root->left, minRange, root->val) &&
                check(root->right, root->val, maxRange)){
                return true;
            }
        } 
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};