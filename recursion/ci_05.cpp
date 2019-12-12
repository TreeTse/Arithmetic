/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的
小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/


/*
解法：
依然是斐波那契数列的解法
当number>2时分两步考虑，
第一次摆放一块 2*1 的小矩阵，则摆放方法总共为f(number-1)
第一次摆放一块 1*2 的小矩阵，则摆放方法总共为f(number-2)
因为，摆放了一块1*2的小矩阵，对应下方的1*2摆放方法就确定了，所以为f(number-2)
*/

class Solution {
public:
    int rectCover(int number) {
        if(number == 0)
            return 0;
        if(number <= 1)
            return 1;
        else if(number == 2)
            return 2;
        else {
            return rectCover(number-1) + rectCover(number-2);
        }
    }
};