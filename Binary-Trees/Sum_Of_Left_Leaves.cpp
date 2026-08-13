// LEETCODE - 404

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
    bool isLeaf(TreeNode* root){
        return root->left == NULL && root->right == NULL;
    }
    
    void findSum(TreeNode* root, int &sum){
        if (root == NULL) return;

        if (root->left && isLeaf(root->left)) sum += root->left->val;
        findSum(root->left, sum);
        findSum(root->right, sum); 
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        findSum(root, sum);
        return sum;
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
    bool isLeaf(TreeNode* root){
        return root->left == NULL && root->right == NULL;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;

        while (curr != NULL){
            if (curr->left == NULL){
                curr = curr->right;
            }else{
                TreeNode* x = curr->left;
                if (isLeaf(x)) sum += x->val;
                
                while (x->right && x->right != curr){
                    x = x->right;
                }

                if (x->right == NULL){
                    x->right = curr;
                    curr = curr->left;
                }else{
                    x->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return sum;
    }
};