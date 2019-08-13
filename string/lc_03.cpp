/*
题目描述：
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，
总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
注意:
字符串长度 和 k 不会超过 104。

示例 1:

输入:
s = "ABAB", k = 2

输出:
4

解释:
用两个'A'替换为两个'B',反之亦然。

示例 2:

输入:
s = "AABABBA", k = 1

输出:
4

解释:
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
*/

/*
解法：使用滑动窗口算法，滑动窗口算法的关键有两点：
一是要找到窗口更新 size 的条件。二是要能找到快速判断条件的方法。
就本题而言，第一点肯定是看窗口内出现次数最多的元素个数 maxCount，
如果有 end-start+1>maxCount+k，就说明有 k 个替换机会也不可能让
所有字符全部相同了，窗口太大需要收缩了。
第二点就是怎么来设计一个方法来快速判断窗口内出现次数最多的元素个数
，一般其实都是用哈希表来解决，本题也不例外，可以用数组的方式实现。
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int l = 0, maxCount = 0, result = 0;
        for(int r = 0; r < s.size(); r++){
            hash[s[r]-'A']++;
            if(maxCount < hash[s[r]-'A']){
                maxCount = hash[s[r]-'A'];
            }
            while(r-l+1-maxCount > k){
                hash[s[l]-'A']--;
                l++;
            }
            if(result < r-l+1){
                result = r-l+1;
            }
        }
        return result;
    }
};

