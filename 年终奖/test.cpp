class Bonus {
public:
int getMost(vector<vector<int> > board) {
int length = board.size();
int wideth = board[0].size();
vector<vector<int>> allPrice;
for (int i = 0; i < length; i++) {
vector<int> tmp(wideth, 0);
allPrice.push_back(tmp);
} a
llPrice[0][0] = board[0][0];
for (int i = 0; i < length; i++) {
for (int j = 0; j < wideth; j++) {
//如果是起点坐标，不做任何处理。
if (i == 0 && j == 0)
continue;
//如果走在行的临界边，也就是第一行，那么他只能向右走
//向右走的时候该点就要将后面的值加起来。
else if (i == 0) {
	allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
}
//如果走在列的临界边，也就是第一列，那么他只能向下走
//向下走的时候该点就要将上面的值加起来。
else if (j == 0) {
allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
} e
lse {
//除去两个临界边，剩下的就是既能向右走，也能向下走，
//这时候就要考虑走到当前点的所有可能得情况，也就是走到当前点
//各自路径的和是不是这些所有到达该点路径当中最大的了。
allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) + board[i]
[j];
}
}
}
// 返回最后一个坐标点的值，它就表示从左上角走到右下角的最大奖励
return allPrice[length - 1][wideth - 1];
}
};