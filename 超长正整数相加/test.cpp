#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string addStrings(string num1, string num2) {
//由低位向高位相加
int i = num1.size() - 1;
int j = num2.size() - 1;
string result = "";
//当前位的相加结果
int carry = 0;
while (i >= 0 || j >= 0)
{ if (i >= 0) {
carry += num1[i] - '0';
} i
f (j >= 0) {
carry += num2[j] - '0';
} /
/当前为的最大值不大于10
result += (char)(carry % 10 + '0');
//如果大于10,向上进一位
carry /= 10;
i--;
j--;
}
//相加完之后，如果还有进位，则再加1
if (carry == 1)
{ result += '1';
}//整体逆置
reverse(result.begin(), result.end());
return result;
} i
nt main()
{
string s1, s2;
while(cin>>s1>>s2)
{ c
out<<addStrings(s1, s2)<<endl;
} r
eturn 0;
}