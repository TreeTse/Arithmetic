/*
题目描述：
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

示例 1:

输入: "A"
输出: 1

示例 2:

输入: "AB"
输出: 28
*/


class Solution {
public:
    int titleToNumber(string s) {
        map<char,int> m;
        for(char i = 'A';i <= 'Z';i++){
            m[i] = i - 'A' + 1;
        }
        int des = 0;
        for(int i = 0;i < s.size();i++){
            des = des*26 + m[s[i]];
        }
        return des;
    }
};

