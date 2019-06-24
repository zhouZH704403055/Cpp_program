#
include <string>
#include <iostream>
using namespace std;
int main()
{
string s;
while(cin>>s)
{
int hashtable[256] = {0};
for(auto& e : s)
{
hashtable[e]++;
} i
nt i;
for(i = 0; i < s.size(); i++)
{
if(hashtable[s[i]] == 1)
{cout<<s[i]<<endl;
break;
}
} i
f(i >= s.size())
cout<<-1<<endl;
} r
eturn 0;
}