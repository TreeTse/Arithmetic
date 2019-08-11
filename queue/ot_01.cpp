/*
题目描述：
一块金条切成两半，是需要花费和长度数值一样的铜板的。比如长度为20的 金条，不管切成长度多大的两半，都要花费20个铜
板。一群人想整分整块金 条，怎么分最省铜板？例如,给定数组{10,20,30}，代表一共三个人，整块金条长度为10+20+30=60
. 金条要分成10,20,30三个部分。 如果， 先把长度60的金条分成10和50，花费60 再把长度50的金条分成20和30，花费50一
共花费110铜板。但是如果， 先把长度60的金条分成30和30，花费60 再把长度30金条分成10和20，花费30 一共花费90铜板。
输入一个数组，返回分割的最小代价。
*/

/*
解法：使用一个优先队列来完成，思路类似于哈夫曼编码的思想
*/

#include<iostream>
#include<queue>
using namespace std;
//比较器，小根堆
struct cmp {
	bool operator ()(int &a, int &b){
		return a > b;
	}
};

int lessMoney(int arr[],int length) {
	priority_queue<int, vector<int>, cmp> pQ;
	for (int i = 0; i < length; i++) {
		pQ.push(arr[i]);
	}
	int sum = 0;
	int cur = 0;
	while (pQ.size() > 1) {
		int top1 = pQ.top();  //取堆顶（最小的元素）
		pQ.pop();    //弹出堆顶
		int top2 = pQ.top();
		pQ.pop();
		cur = top1 + top2;
		sum += cur;   
		pQ.push(cur);  //将两最小值组成的和入堆
	}
	return sum;
}

int main() {
	int arr[3] = { 10,20,30 };
	int len = 3;
	cout << lessMoney(arr, len) << endl;
	return 0;
}

