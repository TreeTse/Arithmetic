/*
题目描述：
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/


//设左上角和右下角两个点，顺时针打印一圈后，左上角的点向右下角跳一格，右下角的点向左上角跳一格。


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> getMatrix;
        int i;
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        if(right+1 == 0 || bottom+1 == 0)
            return getMatrix;
        while(left <= right && top <= bottom){
            for(i = left; i <= right; ++i)
                getMatrix.push_back(matrix[top][i]);
            for(i = top+1; i <= bottom; ++i)
                getMatrix.push_back(matrix[i][right]);
            if(top != bottom)
            for(i = right-1; i >= left; --i)
                getMatrix.push_back(matrix[bottom][i]);
            if(left != right)
            for(i = bottom-1; i > top; --i)
                getMatrix.push_back(matrix[i][left]);
            left++; top++; right--; bottom--;
        }
        return getMatrix;
    }
};