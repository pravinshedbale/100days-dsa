#include<iostream>
#include<queue>
#include "TreeNode.h"

TreeNode<int>* takeInputLevelWise() {
    int data;
    cout<<"Enter Data : ";
    cin>>data;

    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int numChilds;
        cout<<"Enter Number of Childs for "<<front->data<<" : ";
        cin>>numChilds;

        for(int i=0; i<numChilds; i++) {
            int childData;
            cout<<"Enter "<<i<<" th child of "<<front->data<<" : ";
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        } 
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size()!=0) {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->children.size()!=0) {
             for(int i=0; i<front->children.size()-1; i++) {
                 cout<<front->children[i]->data<<",";
                 pendingNodes.push(front->children[i]);
        	}
            cout<<front->children[front->children.size()-1]->data;
            pendingNodes.push(front->children[front->children.size()-1]);
        }
        cout<<endl;
    }
}

void printTree(TreeNode<int>* root) {
    if(root==NULL) {
        return;
    }
    
    cout<<root->data<<" : ";
    for(int i=0; i<root->children.size(); i++) {
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++) {
        printTree(root->children[i]);
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout<<"Level Wise Printing"<<endl;
    printLevelWise(root);

    cout<<"Simple Printing";
    printTree(root);
    return 0;
}