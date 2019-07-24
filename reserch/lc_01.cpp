/*
题目描述：编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

    每行的元素从左到右升序排列。
    每列的元素从上到下升序排列。
*/


//解法：从左下角开始向右上角收缩，每一行递增，行首元素最小；每一列递增，列首也最小


class Solution {
public:
    bool searchMatrix(vector <vector<int> >& matrix, int target) {
        if(matrix.empty())
		    return false;
		int i = matrix.size() - 1,j = 0;
		while(i >= 0 && j < matrix[0].size()){
			if(matrix[i][j] == target)
				return true;
			else if(matrix[i][j] > target)
				i--;
			else if(matrix[i][j] < target)
				j++;
		}	
		return false;
    }
};