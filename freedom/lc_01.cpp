/*
题目描述：
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,1]
输出: 1

示例 2:
输入: [4,1,2,1,2]
输出: 4
*/
//解法一：使用异或运算，考虑到其满足交换律和结合律，即a^b^c=a^c^b,遍历一次数组就可得到最终的结果   
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0; 
        for(int i = 0;i< nums.size();i++){ 
            result = nums[i] ^ result; 
        } 
        return result;
    }
};

//解法二：使用map容器来实现
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> ret;
        for(int i=0;i<nums.size();i++){
            if(ret.count(nums[i])==0)
                ret[nums[i]]=1;
            else
                ret[nums[i]]+=1;
        }
        for(auto item:ret){
            if(item.second==1){
                return item.first;
            }
        }
        return 0;
    }
};

