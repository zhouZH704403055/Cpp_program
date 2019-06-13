#include<iostream>
#include<algorithm>
using namespace std;
int count(int n)
{ 
	int cnt = 0;
	if ((n < 0) | (n>500000))
		return -1;
	else 
	{
		for (int i = 2; i <= n; i++)
		{ 
			int sum = 0;
			//遍历范围
			int sq = sqrt(i);
			for (int j = 2; j <= sq; j++)
			{ 
				if (i%j == 0) {
					//如果j^2 = i，说明两个约数相同，只加一个
					if (i / j == j)
						sum += j;
					else
				}
			}
			//否则，两个不同的约数都要相加
			sum += j + (i / j);
			if (sum + 1 == i)
				cnt++;
		}
	return cnt;
	}
} 
int main() 
{
	int input;
	while(cin >> input)
		cout << count(input) << endl;
	return 0;
}