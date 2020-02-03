/*
题目描述：
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
*/

//求最长子串长度，就是把当前位置减去pre（字符上一次出现的位置），在遍历中不断更新求得
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        for(int i = 0; i  < s.length(); i++)
            m[s[i]] = -1;
        int pre = -1, Max = 0;
        for(int i = 0; i  < s.length(); i++){
            pre = max(pre, m[s[i]]);
            Max = max(Max, i-pre);
            m[s[i]] = i;
        }
        return Max;
    }
};