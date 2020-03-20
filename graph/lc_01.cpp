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


//解法一：DFS

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

//解法二：并查集

class Union{
public:
    Union(vector<vector<char>>& grid){
        Count = 0;
        int r = grid.size();
        int c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    ++Count;
                    parent.push_back(i * c + j);
                }
                else
                    parent.push_back(-1);
                rank.push_back(0);
            }
        }
    }
    int getFather(int x){
        while(x != parent[x]){
            x = parent[x];
        }
        return x;
    }
    void toUnion(int x, int y){
        int xf = getFather(x);
        int yf = getFather(y);
        if(xf != yf){
            if(rank[xf] > rank[yf]) parent[yf] = xf;
            else if(rank[xf] < rank[yf]) parent[xf] = yf;
            else {
                parent[yf] = xf;
                rank[xf]++;
            }
            --Count;
        }
    }
    int getCount() const{
        return Count;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int Count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rn = grid.size();
        if(!rn) return 0;
        int cn = grid[0].size();
        Union u(grid);
        for(int i = 0; i < rn; i++){
            for(int j = 0; j < cn; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    if(i - 1 >= 0 && grid[i - 1][j] == '1') u.toUnion(i * cn + j, (i - 1) * cn + j);
                    if(i + 1 < rn && grid[i + 1][j] == '1') u.toUnion(i * cn + j, (i + 1) * cn + j);
                    if(j - 1 >= 0 && grid[i][j - 1] == '1') u.toUnion(i * cn + j, i * cn + j - 1);
                    if(j + 1 < cn && grid[i][j + 1] == '1') u.toUnion(i * cn + j, i * cn + j + 1);
                }
            }
        }
        return u.getCount();
    }
};