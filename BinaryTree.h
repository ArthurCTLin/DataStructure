#ifndef BINARYTREE
#define BINARYTREE

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

class BinaryTree{
    TreeNode *root;
    void showInOrder(TreeNode *);
    void showPreOrder(TreeNode *);
    void showPostOrder(TreeNode *);
    void deleteNode(int num, TreeNode *&nodePtr);

    public:
    BinaryTree(){root = NULL;}
    void insertNode(int);
    void coutInOrder(){ showPostOrder(root); }
    void coutPreOrder(){ showPreOrder(root); }
    void coutPostOrder(){ showPostOrder(root); }
    bool searchNode(int num);
    void removeNode(int num){ deleteNode(num, root); }
    TreeNode* getTargetCopy(TreeNode* , TreeNode*, TreeNode*); //Leetcode #1379 

};

#endif
