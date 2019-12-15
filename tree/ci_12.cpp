/*
题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所
有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路
径。(注意: 在返回值的list中，数组长度大的数组靠前)
*/


//解法：使用递归
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
    vector<vector<int> > res;
    vector<int> path;
    void find(TreeNode* pRoot,int num){
        if(pRoot == NULL)
            return;
        path.push_back(pRoot->val);
        if(!pRoot->left && !pRoot->right && pRoot->val == num)
            res.push_back(path);
        else{
            if(pRoot->left)
                find(pRoot->left,num - pRoot->val);
            if(pRoot->right)
                find(pRoot->right,num - pRoot->val);
        }
        path.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find(root,expectNumber);
        return res;
    }
};