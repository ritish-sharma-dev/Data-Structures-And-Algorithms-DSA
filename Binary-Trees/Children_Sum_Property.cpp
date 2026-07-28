// Coding Ninjas





#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
// TC : O(n)
// SC : O(h)
bool isLeaf(BinaryTreeNode <int> * node){
    return !node->left && !node->right;
}

void change(BinaryTreeNode <int> * node){
    if (!node || isLeaf(node)) return;

    int sum = 0;
    if (node->left) sum += node->left->data;
    if (node->right) sum += node->right->data;

    if (sum < node->data){
        if (node->left) node->left->data = node->data;
        if (node->right) node->right->data = node->data;
    }

    change(node->left);
    change(node->right);

    node->data = 0;
    if (node->left) node->data += node->left->data;
    if (node->right) node->data += node->right->data;
}

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    change(root);
}  