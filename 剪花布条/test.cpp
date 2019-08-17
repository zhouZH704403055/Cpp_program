#include<iostream>
#include<string>
int main()
{
std::string s, t;
while (std::cin >> s >> t)
{
int res = 0;
size_t pos = 0;
//依次在 s 中查找 t 即可，直到再也找不到 t
while ((pos = s.find(t, pos)) != std::string::npos)
{
pos += t.size(); //跳过t串整体的长度
++res; //计数
} s
td::cout << res << std::endl;
} r
eturn 0;
}