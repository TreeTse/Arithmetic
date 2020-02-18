/*
题目描述：
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...
*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0]和B[n-1] = 1）
*/


/*解法：构建一个A(n-1)*B(n-1)的矩阵，其对角线都是1。B[i]的值可以看作是矩阵中每行的
乘积。先求下三角，再求上三角。
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int length = A.size();
        vector<int> B(length);
        if(length != 0){
            B[0] = 1;
            for(int i = 1; i < length; i++){
                B[i] = B[i - 1] * A[i - 1];
            }
            int tmp = 1;
            for(int j = length - 2; j >= 0; j--){
                tmp *= A[j + 1];
                B[j] *= tmp;
            }
        }
        return B;
    }
};
