/*
用字母 A 对应数字 1，B 对应 2，以此类推，用 Z 对应 26。对于 27以上的数字，用两位或更长位的字符串来对应，例如 AA 对应 27，AB 对应 28，AZ 对应 52，LQ 对应 329。
输入任意一个数字，输出其对应的字符串？
解法：采用递归
*/

#include <iostream>
using namespace std;

void solve(int n) {
	if (!n) {
		return ;
	}
	solve(n / 26);
	cout << (char)(n % 26 + 64);
}

int main() {
	int num;
	cin>>num;
	solve(num); 
	return 0;
} 

