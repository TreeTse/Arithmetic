/*
题目描述：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历
和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和
中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

//解法：使用递归的思想

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* root = reConstructBinaryTree(pre,0,pre.size()-1,vin,0,vin.size()-1);
        return root;
    }
private:
    TreeNode* reConstructBinaryTree(vector<int> pre,int pstart,int pend,vector<int> vin,int vstart,int vend){
        if(pstart > pend || vstart > vend)
            return NULL;
        TreeNode* root = new TreeNode(pre[pstart]);
        for(int i = vstart; i <= vend; i++){
            if(vin[i] == pre[pstart]){
                root -> left = reConstructBinaryTree(pre,pstart+1,pstart+i-vstart,vin,vstart,i-1);
                root -> right = reConstructBinaryTree(pre,i-vstart+pstart+1,pend,vin,i+1,vend);
                break;
            }
        }
        return root;
    }
};

