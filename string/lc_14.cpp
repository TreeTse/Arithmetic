/*给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 
字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/


//解法：KMP算法

class Solution {
public:
    void getNext(string s, int len){
        int j = -1;
        next[0] = -1;
        for(int i = 1; i < len; i++){
            while(j != -1 && s[i] != s[j + 1]){
                j = next[j];
            }
            if(s[i] == s[j + 1])
                j++;
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle[0] == '\0')
            return 0;
        int n = haystack.size(), m = needle.size();
        getNext(needle, m);
        int j = -1;
        for(int i = 0; i < n; i++){
            while(j != -1 && haystack[i] != needle[j + 1]){
                j = next[j];
            }
            if(haystack[i] == needle[j + 1]){
                j++;
            }
            if(j == m - 1){
                return i - j;
            }
        }
        return -1;
    }
private:
    string next;
};