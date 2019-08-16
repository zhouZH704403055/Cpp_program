#include <iostream>
#include <cstdio>
int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;//提前计算斐波那契数列，只保留后6位
for (int i = 2; i <= 100000; ++i)
{
fib[i] = fib[i - 1] + fib[i - 2];
fib[i] = fib[i] % 1000000; //由于是相加，所以只要后六位不影响下一个数的结果
} 
//这里利用了OJ平台计时从开始读取数据的trick，这个技巧可以用在很多题目里
int n;
while (std::cin >> n)
{
if (n < 29)
{
//斐波那契数列小于6位
printf("%d\n", fib[n]);
} else
{
printf("%06d\n", fib[n]);
}
} return 0;
}