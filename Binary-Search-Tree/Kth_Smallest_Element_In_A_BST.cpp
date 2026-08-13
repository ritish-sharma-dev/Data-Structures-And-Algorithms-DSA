// LEETCODE - 230


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
    void findAllNodesVal(TreeNode* root, vector<int> &allNodesVal){
        if (root == NULL) return;

        allNodesVal.push_back(root->val);
        findAllNodesVal(root->left, allNodesVal);
        findAllNodesVal(root->right, allNodesVal);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> allNodesVal;
        findAllNodesVal(root, allNodesVal);

        sort(allNodesVal.begin(), allNodesVal.end());

        return allNodesVal[k-1];
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
    void inorder(TreeNode* root, vector<int> &allNodesVal){
        if (root == NULL) return;

        inorder(root->left, allNodesVal);
        allNodesVal.push_back(root->val);
        inorder(root->right, allNodesVal);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> allNodesVal;

        inorder(root, allNodesVal); // A SORTED TRAVERSAL

        return allNodesVal[k-1];
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int cnt = 0;
        int ans = -1;
        while (curr != NULL){
            if (curr->left == NULL){
                cnt++;
                if (cnt == k) ans = curr->val;
                curr = curr->right;
            }else{
                TreeNode* x = curr->left;
                while (x->right && x->right != curr){
                    x = x->right;
                }

                if (x->right == NULL){
                    x->right = curr;
                    curr = curr->left;
                }else {
                    x->right = NULL;
                    cnt++;
                    if (cnt == k) ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};