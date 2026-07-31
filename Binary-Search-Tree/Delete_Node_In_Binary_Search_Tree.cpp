// LEETCODE - 450





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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        if (root->val == key){
            return helper(root);
        }

        TreeNode* temp = root;
        while (temp != NULL){
            if (key < temp->val){
                if (temp->left && temp->left->val == key){
                    temp->left = helper(temp->left);
                    break;
                }else {
                    temp = temp->left;
                }
            }else {
                if (temp->right && temp->right->val == key){
                    temp->right = helper(temp->right);
                    break;
                }else{
                    temp = temp->right;
                }
            }
        }

        return root;
    }

    TreeNode* helper(TreeNode* temp){
        if (temp->left == NULL){
            return temp->right;
        }else if (temp->right == NULL){
            return temp->left;
        }

        TreeNode* lastRight = findLastRight(temp->left);
        TreeNode* rightChild = temp->right;
        lastRight->right = rightChild;
        return temp->left;
    }

    TreeNode* findLastRight(TreeNode* temp){
        if (temp->right == NULL){
            return temp;
        }
        return findLastRight(temp->right);
    }
};