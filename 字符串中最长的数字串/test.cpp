#include<iostream>
#include<string>
using namespace std;
int main()
{
string str,res,cur;
cin>>str;
for(int i=0;i<=str.length();i++)
{
// 数字+=到cur
if(str[i]>='0' && str[i]<='9')
{
cur+=str[i];
} e
lse
{
// 找出更长的字符串，则更新字符串
if(res.size() < cur.size())
res=cur;
else
cur.clear();
}
} c
out<<res;
return 0;
}