// GFG



/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

// TC : O(n)
// SC : O(h) h - maxheight of the binary tree
class Solution {
public:
    bool check(TreeNode* node){
        if (!node) return true;
        if (!node->left && !node->right) return true;

        int sum = 0;
        if (node->left) sum += node->left->val;
        if (node->right) sum += node->right->val;

        if (sum != node->val) return false;

        return check(node->left) && check(node->right);
    }

    bool checkChildrenSum(TreeNode* root) {
        return check(root);
    }
};
