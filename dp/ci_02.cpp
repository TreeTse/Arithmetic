/*
题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也
可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
解法：使用贪心思想。先进行数学分析归纳，得出结论，代码简洁不少
f(1) = 1
f(2) = f(2-1) + f(2-2)         //f(2-2) 表示2阶一次跳2阶的次数。
f(3) = f(3-1) + f(3-2) + f(3-3) 
...
f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n) 
这里的f(n) 代表的是n个台阶有一次1,2,...n阶的 跳法数。
 n = 3时，会有三种跳的方式，1阶、2阶、3阶， 
那么就是第一次跳出1阶后面剩下：f(3-1);第一次跳出2阶，剩下f(3-2)；第一次3阶，那么剩下f(3-3)
因此结论是f(3) = f(3-1)+f(3-2)+f(3-3) 
n = n时，会有n中跳的方式，1阶、2阶...n阶，得出结论：
f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n) => f(0) + f(1) + f(2) + f(3) + ... + f(n-1) 
继续简化，可以得出：
f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)
f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)
可以得出：f(n) = 2*f(n-1) 
*/


class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 0) {
            return -1;
        } else if (number == 1) {
            return 1;
        } else {
            return 2 * jumpFloorII(number - 1);
        }
    }
};