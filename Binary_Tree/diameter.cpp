// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/description/

// Note: height() will give no. of nodes in longest path
// Actual height of Tree = No. of Nodes - 1
class Solution {
    int dia=0;
    int height(TreeNode* root){
        if(!root) return 0;
        int left=height(root->left);
        int right=height(root->right);
        dia=max(dia,left+right);
        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dia;
    }
};