/*
题目描述：
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"

示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

*/



class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size();
        int lb = b.size();
        if(la < lb){
            swap(a, b);
            swap(la, lb);
        }
        if(la > lb)
            b.insert(0, la - lb, '0');
        string ans;
        int cur = 0, pre = 0;
        for(int i = la - 1; i >= 0; i--){
            int ai = a[i] - '0';
            int bi = b[i] - '0';
            cur = ai ^ bi ^ pre;  //使用异或运算
            if(ai + bi + pre >= 2)
                pre = 1;
            else 
                pre = 0;
            ans.insert(0, 1, cur + '0'); //在0的位置插入1个字符cur
        }
        if(pre)
            ans.insert(0, 1, pre + '0');  //对最高位的进位情况进行处理
        return ans;
    }
};




