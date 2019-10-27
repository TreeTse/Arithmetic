/*
题目描述：
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:

输入一个字符串,包括数字字母符号,可以为空

输出描述:

如果是合法的数值表达则返回该数字，否则返回0

示例1
输入
复制

+2147483647
    1a33

输出
复制

2147483647
    0

*/



class Solution {
public:
    int StrToInt(string str) {
        int n = str.size(), s = 1;
        long long res = 0;
        if(!n) return 0;
        if(str[0] == '-') s = -1;
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){
            if(!('0' <= str[i] && str[i] <= '9')) return 0;
            res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';
        } 
        if(res*s >= -2147483648 && res*s <= 2147483647)
            return res*s;
        else 
            return 0;
    }
};
