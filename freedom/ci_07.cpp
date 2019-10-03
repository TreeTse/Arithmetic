/*
题目描述：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如
输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过
数组长度的一半，因此输出2。如果不存在则输出0。

思路：
如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。在遍历
数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前
保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数
置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
*/


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())    
            return 0;
        int times=1;
        int result=numbers[0];
        vector<int> nums;
        for(int i=1;i<numbers.size();i++){
            if(times==0){
                result=numbers[i];
                times=1;
            }
            else if(numbers[i]==result)
                ++times;
            else
                --times;
        }
        times=0;
        for(int i=0;i<numbers.size();i++){
            if(result==numbers[i])
               ++times;
        }
        return (times>numbers.size()/2)?result:0;
    }
};