/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/


//解法：使用栈来解决

//从根节点开始，先将根节点压入栈
//然后再将其所有左子结点压入栈，取出栈顶节点，保存节点值
//再将当前指针移到其右子节点上，若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curNode = root;
        stack<TreeNode*> st;
        while(curNode || !st.empty()){
            if(curNode){
                st.push(curNode);
                curNode = curNode -> left;
            }else{
                curNode = st.top();
                st.pop();
                result.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        return result;
    }
};
