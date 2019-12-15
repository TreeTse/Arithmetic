/*
题目描述
统计一个数字在排序数组中出现的次数。
*/



//解法1：直接使用C++ STL库

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto r = lower_bound(data.begin(),data.end(),k);
        auto l = upper_bound(data.begin(),data.end(),k);
        return l-r;
    }
};

/*
解法2：因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
这两个数应该插入的位置，然后相减即可。
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return BiSearch(data,k+0.5) - BiSearch(data,k-0.5);
    }
    int BiSearch(const vector<int>& array,double num){
        int l = 0 , r = array.size()-1;
        while(l <= r){
            int mid = (r + l)/2;
            if(array[mid] < num)
                l = mid + 1;
            else if(array[mid] > num)
                r = mid - 1;
         }
         return l;
     }
};