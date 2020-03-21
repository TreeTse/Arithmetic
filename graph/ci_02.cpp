/*题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，
下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18
时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/


//解法：使用回溯法，开辟一个数组用于标记可被到达的格子


class Solution {
public:
    int getSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    bool checkNum(int cx, int cy, int rows, int cols, int threshold, int *v){
        if(cx >= 0 && cx < rows && cy >= 0 && cy < cols && getSum(cx) + 
          getSum(cy) <= threshold && !v[cx * cols + cy])
            return true;
        return false;
    }
    int movingCountCore(int x, int y, int threshold, int* v, int rows, int cols){
        int count = 0;
        if(checkNum(x, y, rows, cols, threshold, v)){
            v[x * cols + y] = 1;
            count = 1 + movingCountCore(x - 1, y, threshold, v, rows, cols)
                + movingCountCore(x + 1, y, threshold, v, rows, cols)
                + movingCountCore(x , y - 1, threshold, v, rows, cols)
                + movingCountCore(x , y + 1, threshold, v, rows, cols);
        }
        return count;
    }
    int movingCount(int threshold, int rows, int cols){
        if(threshold <= 0 || rows <= 0 || cols <= 0)
            return 0;
        int *visited = new int[rows * cols];
        for(int i = 0; i < rows * cols; i++){
            visited[i] = 0;
        }
        int count = movingCountCore(0, 0, threshold, visited, rows, cols);
        delete []visited;
        return count;
    }
};