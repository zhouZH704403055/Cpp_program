// 创建数字映射的字符串数组
string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
// 核心思想：总计深度为digits.size()层的递归，
// 每层递归在字符串中一个字符进行组合。
void combineStr(const string& digits, size_t index, const string& str, vector<string>&
strs)
{
if(index == digits.size())
{
strs.push_back(str);
return;
}
// 获取数字对应的字符数组
string letters = letterMap[digits[index]-'0'];
for(size_t i = 0; i < letters.size(); ++i)
{
combineStr(digits, index+1, str+letters[i], strs);
}
}
vector<string> letterCombinations(string digits) {
vector<string> strs;
if(digits.empty())
return strs;
size_t index = 0;
string str;
// 递归子问题组合字符串
combineStr(digits, index, str, strs);
return strs;
}
};