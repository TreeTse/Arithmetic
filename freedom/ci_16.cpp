/*
题目描述：
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的
任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵
中的某一个格子，则该路径不能再进入该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（
路径中的字母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵
中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H
*/
​	

//解法：回溯法。

class Solution {
public:
    bool hasPath(const char* matrix, int rows, int cols, const char* str){
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        bool *flag = new bool[rows * cols];
        memset(flag, 0, rows * cols);
        int pathlength = 0;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(isPath(matrix, row, col, rows, cols, flag, pathlength, str))
                    return true;
            }
        }
        delete[] flag;
        return false;
    }
    bool isPath(const char* matrix, int row, int col, int rows, int cols, bool* flag, 
                int& pathlength, const char* str){
        if(str[pathlength] == '\0')
            return true;
        bool stepPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols &&
              matrix[row * cols + col] == str[pathlength] && !flag[row * cols + col]){
            ++pathlength;
            flag[row + cols + col] = true;
            stepPath = isPath(matrix, row, col - 1, rows, cols, flag, pathlength, str)
            || isPath(matrix, row - 1, col, rows, cols, flag, pathlength, str)
            || isPath(matrix, row, col + 1, rows, cols, flag, pathlength, str)
            || isPath(matrix, row + 1, col, rows, cols, flag, pathlength, str);
            if(!stepPath){
                --pathlength;
                flag[row * cols + col] = false;
            }
        }
        return stepPath;
    }
};