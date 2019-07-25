/*
描述：
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

/*
解法：使用map容器来记录元素的值和索引，遍历数组时使用临时变量保存目标值与当前值的差值，然后查找
map容器，看是否和临时变量的值一样，是则查找成功。
要注意的是，record[nums[i]]=i;这段不能写在line28前的位置。一开始我是放在那里，然而这样会导致结
果出现两个同样的元素，例如目标值是6，可能结果都是同个下标值，由3+3组成
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> record;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int difvalue = target-nums[i];
            if(record.find(difvalue)!=record.end()){
                ans.push_back(record[difvalue]);
                ans.push_back(i);
                return ans;
            }
            record[nums[i]]=i;
        }
        return ans;
    }
};