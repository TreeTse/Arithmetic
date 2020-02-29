/*题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/




//使用队列，比较简单

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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > ans;
            if(pRoot != NULL){
                queue<TreeNode*> q;
                q.push(pRoot);
                while(!q.empty()){
                    int loop = 0, nrow = q.size();
                    vector<int> row;
                    while(loop++ < nrow){
                        TreeNode* t = q.front();
                        q.pop();
                        row.push_back(t->val);
                        if(t->left) q.push(t->left);
                        if(t->right) q.push(t->right);
                    }
                    ans.push_back(row);
                }
            }
            return ans;
        }
    
};     
            