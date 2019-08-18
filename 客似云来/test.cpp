#include <iostream>
#define MAX 83 //如果用公式计算，需要接下来两项的值
void solve(long long num[])
{
	for (int i = 2; i < MAX; i++)
	{
		num[i] = num[i - 1] + num[i - 2];
	}
}

long long sum_traversal(long long num[], int from, int to) //解法1：用遍历求和求解
{
	long long ans = 0;
	for (int i = from - 1; i < to; i++) //让数组下标从from - 1遍历到to - 1
	{
		ans += num[i];
	} 
	return ans;
}

long long sum_formula(long long num[], int from, int to) //解法2：用公式求解
{
	return num[to + 1] - num[from]; //第to + 2项的下标是to + 1，第from + 2 - 1项的下标是from
}

int main()
{
	int from, to;
	long long num[MAX] = {1, 1};
	//提前计算Fibonacci数列
	solve(num);
	while (std::cin >> from >> to)
	{
		std::cout << sum_formula(num, from, to) << std::endl; //两个方法二选一。公式更快。
	} 
	return 0;
}