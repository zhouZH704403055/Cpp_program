#include<iostream>
#include<string>
#include<algorithm>using namespace std;
int main()
{
int n;
while (cin >> n)
{
int count = 0, maxCount = 0;
// n右移32次就变为0
while (n)
{
//获取当前位的二进制值
if (n & 1)
{
//如果1的值连续，计数累加，并且跟新最大计数
++count;
maxCount = max(count, maxCount);
} e
lse
{
//如果1的值不连续，重新累加
count = 0;
} /
/右移一次，为获取下一位二进制值做准备
n = n >> 1;
} c
out << maxCount << endl;
} r
eturn 0;
}