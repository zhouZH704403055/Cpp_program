#include <algorithm>
class Solution {
public:
string addStrings(string num1, string num2) {
	int LSize = num1.size();
int RSize = num2.size();
// 以长字符串作为外部循环
if(LSize < RSize)
{
num1.swap(num2);
swap(LSize, RSize);
}
string strRet;
strRet.reserve(LSize+1);
char cRet = 0;
char cstep = 0;
for(size_t i = 0; i < LSize; ++i)
{
cRet = num1[LSize - i - 1] - '0' + cstep;
cstep = 0;
if(i < RSize)
{
cRet += num2[RSize - i - 1] - '0';
}
if(cRet >= 10)
{
cRet -= 10;
cstep = 1;
}
strRet += cRet + '0';
}
if(cstep)
strRet += '1';
reverse(strRet.begin(), strRet.end());
return strRet;
}
};