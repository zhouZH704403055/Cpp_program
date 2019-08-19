#include <iostream>
#include <cstdio>

int main()
{
	long long d[22] = { 0, 0, 1 }; // 错排数量，预留第一项为0，配合下文中输入的n
	long long f[22] = { 0, 1, 2 }; // 阶 乘
	for (int i = 3; i < 22; i++)
	{
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); //错排的递推公式
		f[i] = i * f[i - 1]; //阶乘的递推公式
	} 
	int n;
	while (std::cin >> n)
	{
		printf("%.2f%%\n", 100.0 * d[n] / f[n]); //用100.0来把结果处理成double，保留两位小数
	} 
	return 0;
}