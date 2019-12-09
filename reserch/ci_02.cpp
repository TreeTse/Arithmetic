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



class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
    }
private:
    int biSearch(const vector<int> & data, double num){
        int s = 0, e = data.size()-1;     
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(data[mid] < num)
                s = mid + 1;
            else if(data[mid] > num)
                e = mid - 1;
        }
        return s;
    }
};