/*
题目描述：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/


//解法：二叉树的结点数据要存储到一个容器里边，这个容器可以使用队列。


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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        TreeNode* fr = root;
        if(root == NULL)
            return result;
        que.push(root);
        while(!que.empty()){
            fr = que.front();
            if(fr->left != NULL)
                que.push(fr->left);
            if(fr->right != NULL)
                que.push(fr->right);
            result.push_back(fr->val);
            que.pop();
        }
        return result;
    }
private:
    vector<int> result;
    queue<TreeNode*> que;
};