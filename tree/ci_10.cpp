/*
题目描述：
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/


//递归解法

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1 == NULL)
            return false;
        if(pRoot2 == NULL)
            return false;
        return issubTree(pRoot1,pRoot2)||issubTree(pRoot1->left,pRoot2)||issubTree(pRoot1->right,pRoot2);
    }
    bool issubTree(TreeNode* node1,TreeNode* node2){
        if(node2 == NULL)
            return true;
        if(node1 == NULL)
            return false;
        if(node1->val == node2->val)
            return issubTree(node1->left,node2->left)&&issubTree(node1->right,node2->right);
        else 
            return false;
    }
};