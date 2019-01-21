#include <iostream>
#include <algorithm>
#include <assert.h>#include <string>
using namespace std;
namespace zhou
{
template<class T>
class Vector
{
public:
// Vector的迭代器是一个原生指针
typedef T* Iterator;
typedef const T* ConstIterator;
Iterator Begin() { return _start; }
Iterator End() { return _finish; }
ConstIterator CBegin() const { return _start; }
ConstIterator CEnd() const { return _finish; }
size_t Size() const { return _finish - _start; }
size_t Capacity() const { return _endOfStorage - _start; }
Vector()
: _start(nullptr)
, _finish(nullptr)
, _endOfStorage(nullptr)
{}
Vector(int n, const T& value = T())
: _start(nullptr)
, _finish(nullptr)
, _endOfStorage(nullptr)
{
Reserve(n);
while (n--)
{
PushBack(value);
}
}
// 这里如果使用Iterator做迭代器，就会导致初始化的迭代器区间[first,last]只能是Vector的迭代器
// 这里重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器区间。
template<class InputIterator>
Vector(InputIterator first, InputIterator last)
{
Reserve(last - first);
while (first != last)
{
PushBack(*first);
++first;
}
}Vector(const Vector<T>& v)
: _start(nullptr)
, _finish(nullptr)
, _endOfStorage(nullptr)
{
Reserve(v.Capacity());
Iterator it = Begin();
ConstIterator vit = v.CBegin();
while (vit != v.CEnd())
{
*it++ = *vit++;
}
_finish = _start + v.Size();
_endOfStorage = _start + v.Capacity();
}
Vector<T>& operator= (Vector<T> v)
{
Swap(v);
return *this;
}
~Vector()
{
delete[] _start;
_start = _finish = _endOfStorage = nullptr;
}
void Reserve(size_t n)
{
if (n > Capacity())
{
size_t size = Size();
T* tmp = new T[n];
// 这里直接使用memcpy是有问题的
// 以后我们会用更好的方法解决
//if (_start)
// memcpy(tmp, _start, sizeof(T)*size);
if (_start)
{
for (size_t i = 0; i < size; ++i)
tmp[i] = _start[i];
}
_start = tmp;
_finish = _start + size;
_endOfStorage = _start + n;
}
}void Resize(size_t n, const T& value = T())
{
// 1.如果n小于当前的size，则数据个数缩小到n
if (n <= Size())
{
_finish = _start + n;
return;
}
// 2.空间不够则增容
if (n > Capacity())
{
Reserve(n);
}
// 3.将size扩大到n
Iterator it = _finish;
Iterator _finish = _start + n;
while (it != _finish)
{
*it = value;
++it;
}
}
void Swap(Vector<T>& v)
{
swap(_start, v._start);
swap(_finish, v._finish);
swap(_endOfStorage, v._endOfStorage);
}
void PushBack(const T& x)
{
Insert(End(), x);
}
void PopBack()
{
Erase(--End());
}
Iterator Insert(Iterator pos, const T& x)
{
assert(pos <= _finish);
// 空间不够先进行增容
if (_finish == _endOfStorage)
{
size_t size = Size();
size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
Reserve(newCapacity);2.2 对bit::Vector进行严格的测试
// 如果发生了增容，需要重置pos
pos = _start + size;
}
Iterator end = _finish - 1;
while (end >= pos)
{
*(end + 1) = *end;
--end;
}
*pos = x;
++_finish;
return pos;
}
// 返回删除数据的下一个数据
// 方便解决:一边遍历一边删除的迭代器失效问题
Iterator Erase(Iterator pos)
{
// 挪动数据进行删除
Iterator begin = pos + 1;
while (begin != _finish) {
*(begin - 1) = *begin;
++begin;
}
--_finish;
return pos;
}
T& operator[](size_t pos)
{
return _start[pos];
}
private:
Iterator _start; // 指向数据块的开始
Iterator _finish; // 指向有效数据的尾
Iterator _endOfStorage; // 指向存储容量的尾
};
}