// LEETCODE - 144


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


// RECURSIVE
class Solution {
public:
    vector<int> ans;

    void traversal(TreeNode* node){
        if (node == NULL) return;

        ans.push_back(node->val);
        traversal(node->left);
        traversal(node->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        traversal(root);
        return ans;   
    }
};



// ITERATIVE
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack <TreeNode*> st;
        st.push(root);

        while (!st.empty()){
            root = st.top();
            st.pop();
            ans.push_back(root->val);

            if (root->right != NULL){
                st.push(root->right);
            }
            
            if (root->left != NULL){
                st.push(root->left);
            }
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

// MORRIS TRAVERSAL
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;

        TreeNode* curr = root;
        while (curr != NULL){
            if (curr->left == NULL){
                preOrder.push_back(curr->val);
                curr = curr->right;
            }else {
                TreeNode* x = curr->left;
                while (x->right && x->right != curr){
                    x = x->right;
                }

                if (x->right == NULL){
                    x->right = curr;
                    preOrder.push_back(curr->val);
                    curr = curr->left;
                }else {
                    x->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return preOrder;
    }
};