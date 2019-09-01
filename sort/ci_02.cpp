/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

//采用了选择排序的思路


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int index,j,len=input.size();
        if(len==0 || k<=0 || len<k)
            return res;
        for(int i=0;i<k;i++){
            index = i;
            for(int j=i+1;j<len;j++){
                if(input[j]<input[index]){
                    index=j;
                }
            }
            res.push_back(input[index]);
            if(index!=i)
                swap(input[index],input[i]);
        }
        return res;
    }
};