/*
题目描述：
有一个2*n的网格，有一个人位于(1,1)的位置，即左上角，他希望从左上角走到右下角，
即(2,n)的位置。在每一次，他可以进行三种操作中的一种：

1． 向右走一格，即从(x,y)到(x,y+1);

2． 向上右方走一格，即，如果他在(2,y)的位置可以走到(1,y+1);

3． 向下右方走一格，即，如果他在(1,y)的位置可以走到(2,y+1);

 

问题当然不会这么简单，在这2*n的格子中，有一部分格子上有障碍物，他不能停在障碍物上，
当然也不能走出网格，请问他有多少种不同的路线可以到达(2,n)。

输入
输入第一行仅包含一个正整数n，表示网格的长度。(1<=n<=50)

接下来有2行,每行有n个字符，“X”代表障碍物，“.”代表可以停留。

输出
如果没有可以到达的路线则输出-1，否则输出方案数量。


样例输入
5
..X.X
XX...
样例输出
2
*/


//解法一：动态规划，求方案数量，可以从前往后累积计算，右下方格子拥有的路线
//可以由前面的递推出来

#include <iostream>
using namespace std;

int n;
long long dp[2][5500];
string str[2];

int main() {
	cin >> n;
	cin >> str[0] >> str[1];
	if (str[0][0] == 'X') {
		cout << -1 << endl;
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 2; ++j)
			if (str[j][i] == '.') {
				dp[j][i] = dp[j][i-1] + dp[j^1][i-1];
			}
	}
	if (dp[1][n-1] == 0) 
		dp[1][n-1] = -1;
	cout << dp[1][n-1] << endl;
	return 0;
}

