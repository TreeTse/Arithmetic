/*
题目描述：
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1   
   / \  
  2   3  
 / \  /  
4  5 6  
 
输出: 6  
*/  

/*解法：假如一棵满二叉树高度是h，则它的节点数是(1<<h)-1,  
对于一棵完全二叉树的判断，有以下的情况：  
一、
    1  
   / \  
  2   3       
 / \  /  
4  5 6      3的左子树不为空，则整棵二叉树的节点为  

  2          
 / \    
4  5    这一部分的节点数加上1节点再加上右边的子树（右边的子树需要再递归计算）  
二、  
     1    
    / \  
   2   3       
  / \  /\  
 4  5 6  7   
/ \ /\   
8 9 8 9        6的左子树为空，则整棵二叉树的节点数为  
  
   3       
  / \   
 6   7   这一部分的节点数加上1节点再加上左边的子树（左边的子树再递归计算）  
 */  



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        return bs(root,1,getMostLeft(root,1));
    }
    int bs(TreeNode* node,int level,int h){
        if(level == h){
            return 1;
        }
        if(getMostLeft(node->right,level+1) == h)
            return (1 << (h-level)) + bs(node->right,level+1,h);
        else
            return (1 << (h-level-1)) + bs(node->left,level+1,h);
    }
    int getMostLeft(TreeNode* node,int level){
        while(!node){
            node = node->left;
            level++;
        }
        return level-1;
    }
};