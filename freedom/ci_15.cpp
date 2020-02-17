/*
题目描述：
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...
*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0]和B[n-1] = 1）
*/



class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int length = A.size();
        int B[length];
        vector<int> ans;
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
        for(int i = 0; i < length; i++){
            ans.push_back(B[i]);
        }
        return ans;
    }
};