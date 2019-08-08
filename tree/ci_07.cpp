/*
题目描述：
输入一棵二叉树，判断该二叉树是否是平衡二叉树
*/


//解法：递归求左右子树的深度，判断任意某一个节点是不是平衡的，如果都为平衡，则整棵树是平衡的

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        int left = getdeep(pRoot->left);
        int right = getdeep(pRoot->right);
        int diff = left - right;
        if(diff > 1 || diff < -1)
            return false;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
        
    }
private:
    int getdeep(TreeNode* pNode){
        if(pNode == NULL)
            return 0;
        int left = getdeep(pNode->left);
        int right = getdeep(pNode->right);
        return (left > right) ? left+1 : right+1;
    }   
};