/*
题目描述：
给定数列 1, 1, 1, 3, 5, 9, 17, …，从第 4 项开始，每项都是前 3 项的和。求
第 20190324 项的最后 4 位数字。
*/

//解法：类似于斐波那契数列，不能用递归，否则会爆栈；如果求的项数很大的话，到时候肯定会
//溢出的，所以计算过程中需进行取余操作


#include<iostream>
using namespace std;

int solve_value(int num){
	if(num <= 3)
		return 1;
	int a = 1, b = 1, c = 1;
	int res = 0;
	while(num > 3){
		res = (a + b + c)% 10000;
		a = b;
		b = c;
		c = res;
		num--;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int ans = solve_value(n);
	cout << "the answer is " << ans << endl;
	return 0;
}