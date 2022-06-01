using namespace std;
#include<iostream>
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* helper(int *preorder, int *inorder, int ins, int ine, int ps, int pe) {
    if(ins>ine) {
        return NULL;
    }
    int root = preorder[ps];
    int rootIndex = -1;
    for(int i=ins; i<=ine; i++) {
        if(inorder[i]==root) {
            rootIndex = i;
            break;
        }
    }
    
	int lInS = ins;
    int lInE = rootIndex-1;
    int lPreS = ps+1;
    int lPreE = lInE-lInS+lPreS;
    
    int rInS = rootIndex+1;
    int rInE = ine;
    int rPreS = lPreE+1;
    int rPreE = pe;
    
    BinaryTreeNode<int>* rootNode = new BinaryTreeNode<int>(root);
    rootNode->left = helper(preorder, inorder, lInS, lInE, lPreS, lPreE);
    rootNode->right = helper(preorder, inorder, rInS, rInE, rPreS, rPreE);
    return rootNode;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return helper(preorder, inorder, 0, preLength-1, 0, inLength-1);
}



BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}