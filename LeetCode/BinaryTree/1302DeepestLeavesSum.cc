/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    int max_depth=-1;
    int sum=0;
    void dfs(TreeNode* root, int depth){
        if(!root->left && !root->right){ //There is no child for this node(Leaf)
            if(depth==max_depth) sum+=root->val; //To judge this terminal node whether is max_depth
            else if(depth>max_depth){
                max_depth=depth;
                sum = root->val;
            }
        }
        else{
            depth++; //If this is not the leaf, add the depth and find the next layer
            if(root->left) dfs(root->left, depth);
            if(root->right) dfs(root->right, depth);
        }
    }
    
    
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};