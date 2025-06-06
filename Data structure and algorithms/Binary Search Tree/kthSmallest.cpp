#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode<int>*root,int&i,int k){
    if(root==NULL) return -1;

    //left call

    int left = solve(root->left,i,k);
    if(left!=-1){
        return left;
    }

    i++;
    if(i==k){
        return root->data;
    }

    return solve(root->right,i,k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    return solve(root,i,k);
}