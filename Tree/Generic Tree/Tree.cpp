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


int getHeight(TreeNode<int> *root) {
    int h=0;
    for(int i=0; i<root->children.size(); i++) {
        int childH = getHeight(root->children[i]);
        h = max(childH, h);
    }
    h+=1;
    return h;
}

int getNodeSum(TreeNode<int> *root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int sum = 0;
    while(pendingNodes.size()!=0) {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        sum+=front->data;
        for(int i=0; i<front->children.size(); i++) {
            pendingNodes.push(front->children[i]);
        }
    }
    return sum;
}

int getMaxNode(TreeNode<int> *root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int max = root->data;
    while(pendingNodes.size()!=0) {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front->data>max) {
            max = front->data;
        }
        for(int i=0; i<front->children.size(); i++) {
            pendingNodes.push(front->children[i]);
        }
    }
    return max;
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

void printAtLevelK(TreeNode<int> *root, int k) {
    if(root==NULL) {
        return;
    }
    if(k==0) {
        cout<<root->data<<" ";
    }
    for(int i=0; i<root->children.size(); i++) {
        printAtLevelK(root->children[i], k-1);
    }
}

int numberOfLeafNodes(TreeNode<int> *root) {
    int count=0;
    if(root==NULL) {
        return 0;
    }
    if(root->children.size()==0) {
        count++;
    }
    for(int i=0; i<root->children.size(); i++) {
        count = count + numberOfLeafNodes(root->children[i]);
    }
    return count;
}

void preorder(TreeNode<int> *root) {
    cout<<root->data<<" ";
    for(int i=0; i<root->children.size(); i++){
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root) {
    for(int i=0; i<root->children.size(); i++) {
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

void deleteTree(TreeNode<int> *root) {
    for(int i=0; i<root->children.size(); i++) {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main() {
    int l=2;
    TreeNode<int>* root = takeInputLevelWise();
    cout<<"Level Wise Printing"<<endl;
    printLevelWise(root);

    cout<<"Simple Printing"<<endl;
    printTree(root);

    cout<<"Sum of All Nodes is "<<getNodeSum(root)<<endl;
    
    cout<<"Max of All Nodes is "<<getMaxNode(root)<<endl;
    cout<<"Height of tree is "<<getHeight(root)<<endl;
    
    cout<<"Nodes at Level "<<l<<" : ";
    printAtLevelK(root, l);
    cout<<endl;

    cout<<"Number of leaf nodes are : "<<numberOfLeafNodes(root)<<endl;

    cout<<"Preorder Traversal"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Postorder Traversal"<<endl;
    postorder(root);
    cout<<endl;


    return 0;
}