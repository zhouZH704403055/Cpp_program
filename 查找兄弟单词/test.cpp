#
include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// 判定两个单词是否是兄弟单词
bool isBrother(string str, string s){
// 1. 先判定长度是否相同. 不相同的一定不是兄弟单词
if(str.size() == s.size()){
// 2. 再判定字符串是否完全相同. 相同了也不算兄弟三次
if(str == s)
return false;
// 3. 将两个单词排序. 排序后相同才是兄弟单词(因此参数不能用 const&)
sort(str.begin(), str.end());
sort(s.begin(), s.end());
if(str == s)
return true;
} r
eturn false;} i
nt main(){
int num;
while(cin >> num){
string str;
string word,s;
int index;
vector<string> vs;
// 读取字典中的单词, 把字典放到 vs 中.
for(int i = 0; i < num; ++i){
cin >> str;
vs.push_back(str);
} /
/ [注意!!] 题意说的是 "字典", 因此要将里面的单词按照字典序排序~否则得到的 k 会存在问题.
sort(vs.begin(), vs.end());
// 读入要判定的词和k
cin >> word;
cin >> index;
int counts = 0;
// 统计字典中存在多少个兄弟单词.
for(int i = 0; i < num; ++i){
if(isBrother(word, vs[i])){
counts ++;
// 将第 k 个兄弟单词保存到 s 中.
if(counts == index)
s = vs[i];
}
} /
/ 最后输出结果
if(!vs.empty())
cout << counts << endl;
if(counts >= index)
cout << s << endl;
} r
eturn 0;
}