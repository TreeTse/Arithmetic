/*
题目描述
统计一个数字在排序数组中出现的次数。
*/



//解法：直接使用C++ STL库

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto r = lower_bound(data.begin(),data.end(),k);
        auto l = upper_bound(data.begin(),data.end(),k);
        return l-r;
    }
};