/*
题目描述：
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/


//解法一：使用队列非递归


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return;
        TreeNode *pHead = pRoot;
        queue<TreeNode*> q;
        TreeNode *now = NULL;
        q.push(pHead);
        while(!q.empty()){
            now = q.front();
            q.pop();
            swap(now->left,now->right);
            if(now->left)
                q.push(now->left);
            if(now->right)
                q.push(now->right);
        }
    }
};