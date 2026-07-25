// GFG




/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void f(Node* root, int row, int col, map <int, pair<int,int>> &mp){
        if (root == NULL) return;
        

        if (mp.find(col) == mp.end() ||  row >= mp[col].second) mp[col] = {root->data, row};
        
        
        f(root->left, row + 1, col - 1, mp);
        f(root->right, row + 1, col + 1, mp);
    }
    
    
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        
        map <int, pair<int,int>> mp;
        
        f(root, 0, 0, mp);
        
        for (auto x : mp){
            ans.push_back(x.second.first);
        }
        
        return ans;
    }
};





/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        
        queue<pair<Node*, int>> q;
        map <int, int> mp;
        
        q.push( {root, 0});
        
        while (!q.empty()){
            int s = q.size();
            
            for (int i = 0; i < s; i++){
                Node* node = q.front().first;
                int line = q.front().second;
                q.pop();
                
                mp[line] = node->data;
                
                if (node->left) q.push({node->left, line - 1});
                if (node->right) q.push({node->right, line + 1});
            }
        }
        
        for (auto x : mp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};