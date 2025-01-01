#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertIntoBST(Node *&root,int data){
    //if the root is null then just insert and return 
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    //if the data to be inserted is greater
    if(root->data<data){
        root->right = insertIntoBST(root->right,data);
        
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}
void TakeInput(Node * &root){
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}
void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *front = q.front();
        q.pop();
        cout<<front->data<<" ";
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}

bool searchInBST(Node *root,int x){
    while(root!=NULL){
        if(root->data==x){
            return true;
        }
        else if(root->data<x){
            root = root->right;
        }
        else root = root->left;
    }
    return false;
}

int minValue(Node *root){
    if(root->left==NULL){
        return root->data;
    }

    int data = minValue(root->left);
    return data;
}

int maxValue(Node *root){
    if(root->right==NULL){
        return root->data;
    }

    int data = maxValue(root->right);
    return data;
}
Node* deleteFromBST(Node *root,int x){
    if(root==NULL){
        return NULL;
    }
    if(root->data==x){
        //0 child
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        //1 child left
        if(root->left!=NULL && root->right==NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //1 child right
        if(root->left==NULL && root->right!=NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minValue(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data < x){
        root->right = deleteFromBST(root->right,x);
        return root;
    }
    else{
        root->left = deleteFromBST(root->left,x);
        return root;
    }
}
int main(){
    Node *root  = NULL;
    TakeInput(root);
    levelOrderTraversal(root);
    cout<<minValue(root)<<endl;
    cout<<maxValue(root)<<endl;
    cout<<deleteFromBST(root,7)->data<<endl;
    levelOrderTraversal(root);
    return 0;
}