#
include <iostream>
#include <cstdio>
int main()
{
long long n[91] = { 1, 2 };
for (int i = 2; i <= 90; i++)
{
n[i] = n[i - 1] + n[i - 2];
} i
nt d;
while(std::cin >> d)
{
printf("%lld\n", n[d - 1]);
}
}