#include<iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

class BinaryTree{
    TreeNode *root;
    void showInOrder(TreeNode *);
    void showPreOrder(TreeNode *);
    void showPostOrder(TreeNode *);
    void deleteNode(int, TreeNode *&);
public:
    BinaryTree(){ root = NULL; }
    void insertNode(int);
    void coutInOrder(){ showInOrder(root); }
    void coutPreOrder(){ showPreOrder(root); }
    void coutPostOrder(){ showPostOrder(root); }
    bool searchNode(int);
    void removeNode(int num){ deleteNode(num, root); }
};

void BinaryTree::insertNode(int num){
    // Initial data member
    TreeNode *newNode = new TreeNode;
    TreeNode *tempNode;
    newNode->left = newNode->right = NULL;
    newNode->data = num;

    if(root == NULL) root = newNode;
    else{
        tempNode = root;
        while(tempNode){
            if(num < tempNode->data){
                if(tempNode->left) tempNode = tempNode->left;
                else{
                    tempNode->left = newNode;
                    break;
                }
            }
            else if(num > tempNode->data){
                if(tempNode->right) tempNode = tempNode->right;
                else{
                    tempNode->right = newNode;
                    break;
                }
            }
            else{
                cout << "Repeated data!" << endl;
                break;
            }
        }
    }
}

void BinaryTree::showInOrder(TreeNode *nodePtr){
    if(nodePtr){
        showInOrder(nodePtr->left);
        cout << nodePtr->data << " ";
        showInOrder(nodePtr->right);
    }
}
void BinaryTree::showPreOrder(TreeNode *nodePtr){
    if(nodePtr){
        cout << nodePtr->data << " ";
        showPreOrder(nodePtr->left);
        showPreOrder(nodePtr->right);
    }
}
void BinaryTree::showPostOrder(TreeNode *nodePtr){
    if(nodePtr){
        showPostOrder(nodePtr->left);
        showPostOrder(nodePtr->right);
        cout << nodePtr->data << " ";
    }
}

bool BinaryTree::searchNode(int num){
    TreeNode *nodePtr = root;
    while(nodePtr){
        if(num == nodePtr->data) return true;
        else if(num < nodePtr->data) nodePtr = nodePtr->left;
        else if(num > nodePtr->data) nodePtr = nodePtr->right;
    }
    return false;
}

void BinaryTree::deleteNode(int num, TreeNode *&nodePtr){
    if(num < nodePtr->data) deleteNode(num, nodePtr->left);
    else if(num > nodePtr->data) deleteNode(num, nodePtr->right);
    else{
        TreeNode *tempNode;
        if(nodePtr == NULL) cout << "Can not delete empty node!" << endl;
        else if(nodePtr->right==NULL){
            tempNode = nodePtr;
            nodePtr = nodePtr->left;
            delete tempNode;
        }
        else if(nodePtr->left==NULL){
            tempNode = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNode;
        }
        else{
            tempNode = nodePtr->right;
            while(tempNode->left) tempNode = tempNode->left;
            tempNode->left = nodePtr->left;
            tempNode = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNode;
        }
       
    }
}

int main(){
    BinaryTree intTree;
    cout << "Insert new nodes..." << endl;
    intTree.insertNode(5);
    intTree.insertNode(9);
    intTree.insertNode(1);
    intTree.insertNode(6);
    intTree.insertNode(4);
    cout << "Completed" << endl;

    cout << "Show the data in PreOrder : ";
    intTree.coutPreOrder();
    cout << "\nShow the data in PostOrder : ";
    intTree.coutPostOrder();
    cout << "\nShow the data in InOrder : ";
    intTree.coutInOrder();
    cout << endl;

    int i=3;
    if(intTree.searchNode(i)) cout << i << " is in this binary tree." << endl;
    else cout << i << " can not be found in this binary tree." << endl;

    cout << "Delete node 9" << endl;
    intTree.removeNode(9);
    cout << "Delete node 1" << endl;
    intTree.removeNode(1);
    cout << "Show the data in InOrder : ";
    intTree.coutInOrder();
    cout << endl;

    return 0;
}
