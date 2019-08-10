/*
题目描述：
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/


/*
解法：HashMap存储前两个数组能组成的数及其组成的次数，再遍历后两个数组，查看HashMap中是否
存在两数和的相反数，如果存在，则记录出现的次数，累加便为结果
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> m;
        for(int i = 0;i < A.size();i++){
            for(int j = 0;j < B.size();j++){
                m[A[i] + B[j]]++;
            }
        }
        int res = 0;
        for(int i = 0;i < C.size();i++){
            for(int j = 0;j < D.size();j++){
                if(m.find(-C[i]-D[j]) != m.end()){
                    res += m[-C[i]-D[j]];
                }
            }
        }
        return res;
    }
};


