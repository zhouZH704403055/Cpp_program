#include<iostream>
#include<string>
using namespace std;
// 判断是否是回文
bool IsCircleText(const string& s)
{
size_t begin = 0;
size_t end = s.size()-1;
while(begin < end)
{
if(s[begin] != s[end])
return false;
++begin;
--end;
} r
eturn true;
} i
nt main()
{
std::string str1, str2;
getline(cin, str1);
getline(cin, str2);
size_t count = 0;
for(size_t i = 0; i <= str1.size(); ++i)
{
// 将字符串2插入到字符串1的每个位置，再判断是否是回文
string str = str1;
str.insert(i, str2);
if(IsCircleText(str))
++count;
} c
out<<count<<endl;
return 0;
}