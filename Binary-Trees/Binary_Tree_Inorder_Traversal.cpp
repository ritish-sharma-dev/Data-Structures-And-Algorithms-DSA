// LEETCODE - 94


// RECURSIVE
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
    vector<int> ans;

    void traversal(TreeNode* node){
        if (node == NULL) return;

        traversal(node->left);
        ans.push_back(node->val);
        traversal(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if (node != NULL){
                st.push(node);
                node = node->left;
            }else {
                if (st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
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
 // MORRIS ALGORITHM
 // TC : O(n)
 // SC : O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        TreeNode* curr = root;
        while (curr != NULL){
            if (curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }else {
                TreeNode* x = curr->left;
                while (x->right && x->right != curr){
                    x = x->right;
                }

                if (x->right == NULL){
                    x->right = curr;
                    curr = curr->left;
                }else {
                    x->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};