/*题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为
k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们
把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
输入描述:
输入一个数n，意义见题面。（2 <= n <= 60）
输出描述:
输出答案。
示例1
输入
8
输出
18
*/


/*解法：
	动态规划求解的特征：
		a. 求一个问题的最优解；
		b. 整体的问题的最优解是依赖于各个子问题的最优解；
		c. 小问题之间还有相互重叠的更小的子问题；
        d. 从上往下分析问题，从下往上求解问题
    从这四方面去分析问题。
    
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    这部分是不需要剪原数就可得出最大值的，数组往后的部分都是利用前面已有的数值递推出来的。
*/


class Solution {
public:
    int cutRope(int number) {
        if(number < 2)
            return 0;
        else if(number == 2)
            return 1;
        else if(number == 3)
            return 2;
        int *products = new int[number + 1];
        int max;
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        for(int i = 4; i <= number; ++i){
            max = 0;
            for(int j = 1; j <= i/2; ++j){
                int tmp = products[j] * products[i - j];
                if(tmp > max)
                    max = tmp;
            }
            products[i] = max;
        }
        max = products[number];
        delete []products;
        return max;
    }
};