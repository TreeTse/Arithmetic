/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/


//解法：使用队列，非递归，成对比较；在入队的时候要成对成对，在出队的时候也是成对成对
//可以与ci_14.cpp的题相比较

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
        TreeNode* pHead = pRoot;
        queue<TreeNode*> q;
        q.push(pHead->left);
        q.push(pHead->right);
        while(!q.empty()){
            TreeNode* pleft = q.front();
                q.pop();
            TreeNode* pright = q.front();
                q.pop();
            if(pleft == NULL && pright == NULL)
                continue;
            if(pleft == NULL || pright == NULL)
                return false;
            if(pleft->val != pright->val)
                return false;
            q.push(pleft->left);
            q.push(pright->right);
            q.push(pleft->right);
            q.push(pright->left);
        }
        return true;
    }
};


