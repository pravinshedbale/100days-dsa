#include<iostream>
#include<queue>
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

TreeNode<int>* getTreeLevelWise() {
    queue<TreeNode<int>*> pendingNode;
    int data;
    cin>>data;
    if(data==-1) {
        return NULL;
    }
    TreeNode<int> *root = new TreeNode<int>(data);
    pendingNode.push(root);
    while(pendingNode.size()!=0) {
        int leftData, rightData;
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cin>>leftData>>rightData;
        if(rightData!=-1) {
            TreeNode<int> *left = new TreeNode<int>(leftData);
            front->left = left;
            pendingNode.push(left);
        }
        if(rightData!=-1) {
            TreeNode<int> *right = new TreeNode<int>(rightData);
            front->right = right;
            pendingNode.push(right);
        }
    } 
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

void printLevelWise(TreeNode<int> *root) {
    if(root==NULL) {
        return ;
    }
    cout<<root->data<<" ";
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0) {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front->left) {
            cout<<front->left->data<<" ";
            pendingNodes.push(front->left);
        }
        if(front->right) {
            cout<<front->right->data<<" ";
            pendingNodes.push(front->right);
        }
    }
}

int main() {
    TreeNode<int> *root = getTreeLevelWise();
    cout<<"Inorder Traversal"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Print Level Wise"<<endl;
    printLevelWise(root);
    cout<<endl;
    return 0;
}