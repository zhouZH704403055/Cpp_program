#include<deque>
template<class T, class Con = deque<T>>
class Stack
{
public:
Stack() {}
void Push(const T& x) {_c.push_back(x);}
void Pop() {_c.pop_back();}
T& Top() {return _c.back();}
const T& Top()const {return _c.back();}
size_t Size()const {return _c.size();}
bool Empty()const {return _c.empty();}
private:
Con _c;
};
void TestStack()
{
// 适配体现在第二个模板参数可以使用不同的容器，然后适配生成的stack效果是一样的。
//Stack<int, deque<int>> s;
//Stack<int, vector<int>> s;
//Stack<int, list<int>> s;
Stack<int> s;
s.Push(1);
s.Push(2);
s.Push(3);
s.Push(4);
cout << s.Size() << endl;
cout << s.Top() << endl;4.3.2 queue的模拟实现
s.Pop();
s.Pop();
cout << s.Size() << endl;
cout << s.Top() << endl;
}