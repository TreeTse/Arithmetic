

/*
题目描述:二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉
树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），
以 ！ 表示一个结点值的结束（value!）。
*/

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
    char* Serialize(TreeNode *root) {
       if(root == NULL)
           return NULL;
        string str;
        Serialize(root, str);
        char *ret = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++){
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string& str){
        if(root == NULL){
            str += '#';
            return ;
        }
        string s = to_string(root->val);
        str += s;
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
};

