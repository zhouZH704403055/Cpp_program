#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, table="0123456789ABCDEF";
	int m,n;
	cin>>m>>n;
	bool flag = false;
	// 如果是负数，则转成正数，并标记一下
	if(m < 0)
	{
		m = 0 - m;
		flag = true;
	} 
	// 按进制换算成对应的字符添加到s
	while(m)
	{
		s += table[m%n];
		m /= n;
	} 
	if(flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout<<s<<endl;
	return 0;
}