/*
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/


class Solution {
public:
     int  NumberOf1(int n) {
         int sum=0;
         int index=1;
         while(index!=0){
             if((n&index)!=0)
                 sum++;
             index=index<<1;
         }
         return sum;
     }
};



/*
使用移位运算符可以简单求解，注意：line13不能写成if((n&index)==1),否则会出错
*/ 