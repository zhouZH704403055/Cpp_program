class Solution {
public:
// 核心思想：找出杨辉三角的规律，发现每一行头尾都是1，中间第[j]个数等于上一行[j-1]+[j]
vector<vector<int>> generate(int numRows) {
vector<vector<int>> vv;
// 先开辟杨辉三角的空间
vv.resize(numRows);
for(size_t i = 1; i <= numRows; ++i)
{
vv[i-1].resize(i, 0);
// 每一行的第一个和最后一个都是1
vv[i-1][0] = 1;
vv[i-1][i-1] = 1;
}
for(size_t i = 0; i < vv.size(); ++i)
{
for(size_t j = 0; j < vv[i].size(); ++j)
{
if(vv[i][j] == 0)
{
vv[i][j] = vv[i-1][j-1] + vv[i-1][j];
}
}
}
return vv;
}
};