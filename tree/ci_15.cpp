/*
题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    
中，按结点数值大小顺序第三小结点的值为4。
*/


//解法：采用stack来访问结点，先将根结点入栈，然后将此结点的左孩子依次全部
//入栈直至为空，弹出栈顶后将其右孩子入栈,重复此过程直到找到对应的结点

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k){
        if(!pRoot)return nullptr;
        stack<TreeNode*> st;
        TreeNode* tmp = pRoot;
        while(!st.empty() || tmp){
            while(tmp){
                st.push(tmp);
                tmp = tmp->left;
            }
            TreeNode* node = st.top();
            st.pop();
            if((--k) == 0)
                return node;
            tmp = node->right;
        }
        return nullptr;
    }
};