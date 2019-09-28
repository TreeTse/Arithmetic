


//采用递归法


#include <stdio.h> 

void prim(int m, int n, bool b = true) {//m 是待分解的数，n 代表m当前最小可能的因子, b 代表是否第一个因子
	if(m>n) {
		while(m%n != 0) n++;
		m /= n;
		prim(m, n, false);
		if (!b)
		{
			printf("%d*", n);
		}
		else
		{
			printf("%d", n);
		}
	}
}

int main()
{
	int n = 435234;
	printf("%d=", n);
	prim(n, 2);
	//prim2(n);
	return 0;
}