
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if(root==NULL){
        return nullptr;
    }

    if(root->data<P->data && root->data<Q->data){
        return LCAinaBST(root->right, P, Q);
    }
    if(root->data>P->data && root->data>Q->data){
        return LCAinaBST(root->left, P, Q);
    }
    return root;
}