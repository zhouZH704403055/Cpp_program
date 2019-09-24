#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
string getFileName(string path){
int pos = path.rfind('\\');
return path.substr(pos + 1);
} s
tring modifyName(string name){
if (name.size() > 16){
name = name.substr(name.size() - 16);
} r
eturn name;
} s
truct ErrRecord{
string file;
int lineNo;
int count;
ErrRecord(string file, int lineNo){
this->file = file;
this->lineNo = lineNo;
count = 1;
}
// 后续需要进行查找, 所以先定义好两个错误记录什么情况算相等.
bool operator==(const ErrRecord & a){
return (file == a.file) && (lineNo == a.lineNo);
}
};
int main(){
string file;
int lineNo;
vector<ErrRecord> myvec;
while (cin >> file >> lineNo) {ErrRecord record(getFileName(file), lineNo);
auto res = find(myvec.begin(), myvec.end(), record);
if (res == myvec.end()){
myvec.push_back(record);
} else {
res->count++;
}
} i
nt count = 0;
for (auto item : myvec){
if (count + 8 >= myvec.size()){
cout << modifyName(item.file) << " " << item.lineNo << " "
<< item.count << endl;
} c
ount++;
} r
eturn 0;
}