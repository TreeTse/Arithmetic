/*
题目描述：
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

请你返回最终形体的表面积。
*/

/*
题解：
双重循环，遍历每一个柱体。
先不考虑顶部的面积和底部的面积，只考虑四周的面积。
对于相邻两个柱体，都是由靠右/下的柱体来负责减去重叠面积。
全部计算好之后，再把顶部和底部面积加回来。

考虑4种情况：

    左上角顶点,唯一一个左边和上面都没有被挡住的柱体，因此单独考虑。
    除顶点外，最上面一行的柱体，上边都没有被挡住。
    除顶点外，最左边一列的柱体，左边都没有被挡住。
    剩余其他柱体。
    对于情况1，我们单独列出来就可以了。
    对于情况2，我们对于每一个柱体，我们只需要考虑当前柱体的左边一个柱体与自己的重叠面积。
    对于情况3，我们只需要考虑当前柱体和上面一个柱体的重叠面积。
    对于情况4，要考虑当前柱体和左边一个柱体，以及上面一个柱体的重叠面积。
    (对于最后一行和最后一列，因为还没有再往后/右的柱体了，所以考虑方式是和情况4相同的)
    最后再把顶部面积和底部面积加回来(长*宽)。
    额外情况5，如果有高度为0的柱体，那么没有顶部和底部面积，要记得减掉。
*/


class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int zeronums = 0;
        int sumnum = 0;
        if(n == 0 || m == 0)
            return 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) zeronums++;
                else if(i == 0 && j == 0) sumnum += 4*grid[0][0];
                else if(i != 0 && j == 0) sumnum += 4*grid[i][j] - 2*min(grid[i][j],grid[i-1][j]);
                else if(i == 0 && j != 0) sumnum += 4*grid[i][j] - 2*min(grid[i][j],grid[i][j-1]);
                else sumnum += 4*grid[i][j] - 2*min(grid[i][j],grid[i-1][j]) - 2*min(grid[i][j],grid[i][j-1]);
            }
        }
        return sumnum + 2*(m*n - zeronums);
    }
};