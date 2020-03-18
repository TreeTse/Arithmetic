/*
题目描述：
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3
*/


//解法：DFS

class Solution {
public:
    void Isdfs(vector<vector<char>>& grid, int curR, int curC, int r, int c){
        if(grid[curR][curC] == '1')
            grid[curR][curC] = '0';
        if(curR + 1 < r && grid[curR + 1][curC] == '1') Isdfs(grid, curR + 1, curC, r, c);
        if(curR - 1 >= 0 && grid[curR - 1][curC] == '1') Isdfs(grid, curR - 1, curC, r, c);
        if(curC + 1 < c && grid[curR][curC + 1] == '1') Isdfs(grid, curR, curC + 1, r, c);
        if(curC - 1 >= 0 && grid[curR][curC - 1] == '1') Isdfs(grid, curR, curC - 1, r, c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(!r) return 0;
        int IsNum = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    ++IsNum;
                    Isdfs(grid, i, j, r, c);
                }
            }
        }    
        return IsNum;
    }
};