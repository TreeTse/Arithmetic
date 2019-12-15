/*
题目描述：
在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和。
例子：
[1,3,4,2,5]
1左边比1小的数，没有；
3左边比3小的数，1；
4左边比4小的数，1、3；
2左边比2小的数，1；
5左边比5小的数，1、3、4、2；
所以小和为1+1+3+1+1+3+4+2=16
*/

/*
解法：使用二路归并排序的方法，求一个数组的小和，可以转化为求每个元素在
小和累加过程中出现的次数，然后将当前元素与次数相乘，累加得到小和。
*/

#include<iostream>
using namespace std;

int merge(int arr[], int l, int m, int r) {
	int *help = new int[r - l + 1];
	int i = 0;
	int p1 = l;
	int p2 = m + 1;
	int res = 0;
	while (p1 <= m && p2 <= r) {
		res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= m) {
		help[i++] = arr[p1++];
	}
	while (p2 <= r) {
		help[i++] = arr[p2++];
	}
	for (i = 0; i < r - l + 1; i++) {
		arr[l + i] = help[i];
	}
	return res;
}

int mergeSort(int arr[],int left,int right) {
	if (left == right)
		return 0;
	int mid = left + ((right-1) >> 1);
	return mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right) + merge(arr, left,mid, right);
}

int smallSum(int arr[],int n) {
	if (arr == NULL || n < 2)
		return 0;
	return mergeSort(arr, 0, n - 1);
}

int main() {
	int array[] = { 1,3,4,2,5 };
	int res = smallSum(array, 5);
	cout << res << endl;
	return 0;
}