/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/


//解法：使用队列，成对比较
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
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(pRoot->left);
        q.push(pRoot->right);
        while(!q.empty()){
            TreeNode* pleft = q.front();
            TreeNode* pright = q.front();
            q.pop();
            q.pop();
            if(pleft == NULL && pright == NULL)
                continue;
            if(pleft == NULL || pright == NULL)
                return false;
            if(pleft != pright)
                return false;
            q.push(pleft->left);
            q.push(pright->right);
            q.push(pleft->right);
            q.push(pright->left);
        }
        return true;
    }
};


