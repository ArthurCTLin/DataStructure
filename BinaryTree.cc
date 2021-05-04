#include "BinaryTree.h"
#include <iostream>

using namespace std;
/*
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/
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

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target){
    if(original==NULL) return NULL;
    if(original==target) return cloned;
    
    TreeNode *c1 = getTargetCopy(original->left, cloned->left, target);
    if(c1!=NULL && c1->data==target->data) return c1;
    
    TreeNode *c2 = getTargetCopy(original->right, cloned->right, target);
    return c2;
}
