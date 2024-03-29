/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

//解法：设头尾两个指针l和r，l和r相差越远的话乘积越小，
//若al+ar==sum √
//若al+ar<sum,l要加
//若al+ar>sum,r要减



class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ans;
        int l = 0, r = array.size()-1;
        while(l < r){
            if(array[l] + array[r] == sum){
                ans.push_back(array[l]);
                ans.push_back(array[r]);
                break;
            }
            while(l < r && array[l] + array[r] < sum) l++;
            while(l < r && array[l] + array[r] > sum) r--;
        }
        return ans;
    }
};
