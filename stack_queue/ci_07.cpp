/*题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
*/




//解法：使用两个栈，左边s1，右边s2，当s1在操作时，按照左右顺序将操作数入栈s2；
//当s2在操作时，按照右左顺序将操作数入栈s1。直到左右两个栈都为空时，程序结束


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
            stack<TreeNode*> s1,s2;
            s1.push(pRoot);
            bool flag = true;
            vector<int> row;
            while(!s1.empty() || !s2.empty()){
                row.clear();
                while(flag && !s1.empty()){
                    TreeNode* cur = s1.top();
                    s1.pop();
                    row.push_back(cur->val);
                    if(cur->left)
                        s2.push(cur->left);
                    if(cur->right)
                        s2.push(cur->right);
                }
                ans.push_back(row);
                flag = false;
                row.clear();
                while(!flag && !s2.empty()){
                    TreeNode* cur = s2.top();
                    s2.pop();
                    row.push_back(cur->val);
                    if(cur->right)
                        s1.push(cur->right);
                    if(cur->left)
                        s1.push(cur->left);
                    if(s2.empty())
                        ans.push_back(row);
                }
                flag = true;
             }
        }
        return ans;
    }
};
            
            