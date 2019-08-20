#include <string>
#include <tuple>
#include <list>
#include <cstdio>
// 求n的阶乘
long long factorial(int n)
{
long long r = 1;
for (int i = 1; i <= n; i++)
{
r *= i;
} 
return r;
} /
/ 求 n, m 的组合 C(n, m)
// 利用 C(n, m) == C(n, n - m) 的特点，计算容易的
long long combination(int n, int m)
{
int max = m > (n - m) ? m : (n - m);
long long numerator = 1;
for (int i = max + 1; i <= n; i++)
{
numerator *= i;
} r
eturn numerator / factorial(n - max);
} /
/ 重命名类型，类似于 typedef 作用
using PrePost = std::tuple<std::string, std::string>;
// 给出一棵树的前序+后序，利用最上面注释的原理
// 把每棵子树的前序+后序切分出来
std::list<PrePost> splitSubTrees(std::string const& pre, std::string const&
post)
{
std::list<PrePost> list{};
size_t preIdx = 1;
size_t lastPost = 0;
while (preIdx < pre.size())
{
char rootValue = pre[preIdx];
size_t postIdx = post.find(rootValue);int countOfNode = postIdx - lastPost + 1;
list.emplace_back(std::make_tuple(
pre.substr(preIdx, countOfNode),
post.substr(lastPost, countOfNode)
)
);
preIdx += countOfNode;
lastPost += countOfNode;
} r
eturn list;
} /
/ 递归的求解每一层的可能性，直到树中只剩一个或者零个结点
long long calculateNumOfPossibilities(int m,
std::string const& pre,
std::string const& post)
{
if (pre.size() == 0 || pre.size() == 1) {
return 1;
} s
td::list<PrePost> subTrees = splitSubTrees(pre, post);
long long result = combination(m, subTrees.size());
for (PrePost const& prePost : subTrees)
{
result *= calculateNumOfPossibilities(m,
std::get<0>(prePost),
std::get<1>(prePost));
} r
eturn result;
} i
nt main()
{
int m;
char pre[30];
char post[30];
while (scanf("%d %s %s", &m, pre, post) != EOF)
{
printf("%lld\n", calculateNumOfPossibilities(m, pre, post));
} r
eturn 0;
}