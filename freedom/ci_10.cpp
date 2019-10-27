/*
题目描述：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/


/*解法：第一次全部异或的结果是所要求的两个数字的异或结果，以异或结果数中的某一为1的位划分两组数，
就可以求出两个只出现一次的数字
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2)
            return;
        int len = data.size();
        int x = 0;
        for(int i = 0; i < len; i++)
            x ^= data[i];
        int n = 1;
        *num1 = 0, *num2 = 0;
        while((x & n) != n)
            n <<= 1;
        for(int i = 0; i < len; i++){
            if((data[i] & n) == n)
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
};

