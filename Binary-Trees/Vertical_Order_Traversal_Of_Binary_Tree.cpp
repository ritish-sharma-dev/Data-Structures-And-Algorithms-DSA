

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
    void f(TreeNode* root, int row, int col, unordered_map <TreeNode*, pair<int, int>> &mp){
        if (root == NULL) return;

        mp[root] = {row, col};

        f(root->left, row + 1, col - 1, mp);
        f(root->right, row + 1, col + 1, mp);
    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        unordered_map <TreeNode*, pair<int, int>> mp;

        f(root,0, 0, mp);

        int lowCol = INT_MAX;
        int HighCol = INT_MIN;

        for (auto x : mp){
            lowCol = min(lowCol, x.second.second);
            HighCol = max(HighCol, x.second.second);
        }

        while (lowCol <= HighCol){
            vector<pair<int,int>> v;
            for (auto x : mp){
                if (x.second.second == lowCol) v.push_back({x.second.first, x.first->val});  
            }

            sort(v.begin(), v.end());
            
            vector<int> colVal;
            for (auto p : v) {
                colVal.push_back(p.second);
            }

            ans.push_back(colVal);
            lowCol++;                               
        }

        return ans;
    }
};