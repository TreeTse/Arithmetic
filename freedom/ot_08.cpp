/*
题目描述：

一天蒜头君得到 nn 个字符串 s_isi​，每个字符串的长度都不超过 1010。

蒜头君在想，在这 nn 个字符串中，以 s_isi​ 为后缀的字符串有多少个呢？
输入格式

第一行输入一个整数 nn。

接下来 nn 行，每行输入一个字符串 s_isi​。
输出格式

输出 nn 个整数，第 ii 个整数表示以 s_isi​ 为后缀的字符串的个数。
数据范围

对于 50\%50% 的数据，1 \le n \le 10^31≤n≤103。

对于 100\%100% 的数据，1 \le n \le 10^51≤n≤105。

所有的字符串仅由小写字母组成。

样例输入复制

3
ba
a
aba

样例输出复制

2
3
1
*/

//对map和substr的使用

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
string s[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
	    cin >> s[i];
	    for (int j = 0; j < s[i].length(); j++) {
	        mp[s[i].substr(j)]++;
	    }
	}
	for (int i = 0; i < n; i++) {
	    cout << mp[s[i]] << endl;
	}
	return 0;
}