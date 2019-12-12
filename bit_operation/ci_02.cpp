/*
题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/


/*
解法：
1、两个数异或运算，相当于每一位相加，而不考虑进位
2、两个数相与运算，并左移一位，相当于求得进位
3、将上述两步结果相加
*/

class Solution {
public:
    int Add(int num1, int num2){
        while(num2 != 0){
            int a = num1 ^ num2;
            int b = (num1 & num2) << 1;
            num1 = a;
            num2 = b;
        }
        return num1;
    }
};