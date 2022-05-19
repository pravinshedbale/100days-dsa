#include<iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* getTree() {
    int rootData;
    cin>>rootData;
    if(rootData==-1) {
        return NULL;
    }
    TreeNode<int> *root = new TreeNode<int>(rootData);
    TreeNode<int> *left = getTree();
    TreeNode<int> *right = getTree();
    root->left = left;
    root->right = right;
    return root;
}
void inorder(TreeNode<int> *root) {
    if(root==NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(TreeNode<int> *root) {
     if(root==NULL) {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode<int> *root) {
    if(root==NULL) {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    TreeNode<int> *root = getTree();
    cout<<"Inorder Traversal"<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}