/*
给出一个序列包含n个正整数的序列A，然后给出一个正整数x，你可以对序列进行任意次操作的，每次操作你可以选择序列中
的一个数字，让其与x做按位或运算。你的目的是让这个序列中的众数出现的次数最多。

请问众数最多出现多少次。

输入
输入第一行仅包含两个正整数n和x，表示给出的序列的长度和给定的正整数。(1<=n<=100000,1<=x<=1000)

接下来一行有n个正整数，即这个序列，中间用空格隔开。(1<=a_i<=1000)

输出
输出仅包含一个正整数，表示众数最多出现的次数。


样例输入
5 2
3 1 3 2 5
样例输出
3
*/

/*
解法：
因为1<=n<=100000，所以创建一个长度为100002的数组aic，可以统计每个数字出现的次数；
统计的过程顺便可以用变量max求出出现次数最大值，并且同时将与x或运算后的数字出现的
次数作比较，更新最大值
*/

#include <iostream>
using namespace std;

#define N 100002
int aic[N];

int main() {
	int n, x, tmp, max = 0, t;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		aic[tmp]++;
		if(aic[tmp] > max)
			max = aic[tmp];
		t = tmp | x;
		if(t != tmp){
			aic[t]++;
			if(aic[t] > max)
				max = aic[t];
		}
	}
	cout << max << endl;
	return 0;
}