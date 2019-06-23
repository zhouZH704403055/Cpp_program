#
include <iostream>
#include <string>
using namespace std;
int main(){
//歌曲数量
int n;
//命令
string order;
while (cin >> n >> order)
{
//将n首歌曲编号1：n , num为光标当前所在歌曲的编号,first为当前屏幕显示页的第一首歌曲的编号
int num = 1, first = 1;
if (n <= 4) //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变
{
for (int i = 0; i < order.size(); i++)
{
if (num == 1 && order[i] == 'U')
num = n;
else if (num == n && order[i] == 'D')
num = 1;
else if (order[i] == 'U')
num--;
else
num++;
} f
or (int i = 1; i <= n - 1; i++)
cout << i << ' ';
cout << n << endl;
cout << num << endl;} e
lse //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
{
for (int i = 0; i < order.size(); i++)
{
if (first == 1 && num == 1 && order[i] == 'U')
{ first = n - 3; num = n; } //特殊翻页1
else if (first == n - 3 && num == n && order[i] == 'D')
{ first = 1; num = 1; } //特殊翻页2
else if (first != 1 && num == first && order[i] == 'U')
{ first--; num--; } //一般翻页1
else if (first != n - 3 && num == first + 3 && order[i] == 'D')
{ first++; num++; } //一般翻页2
else if (order[i] == 'U')
num--; //其他情况1
else
num++; //其他情况2
} f
or (int i = first; i < first + 3; i++)
cout << i << ' ';
cout << first + 3 << endl;
cout << num << endl;
}
} r
eturn 0;
}