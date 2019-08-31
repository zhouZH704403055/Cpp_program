#include <iostream>
#include <cmath>
//long long是两个关键字拼起来的，用起来很不方便，重命名一下
typedef long long _sint64;
//有理数类的声明
class RationalNumber
{
	bool m_infinate; //处理除数为零
	bool m_negative; //处理负数
	_sint64 m_numerator; //分子，方便输出
	_sint64 m_denominator; //分母
_sint64 m_integer; //整数部分
_sint64 m_numeratorAll; //记录无整数分数的分子，方便进行运算
_sint64 calcGCD(_sint64 a, _sint64 b); //求最大公约数的函数
public:
RationalNumber(_sint64 numerator, _sint64 denominator); //构造函数
RationalNumber operator+(RationalNumber const& o) const; //四则运算重载
RationalNumber operator-(RationalNumber const& o) const;
RationalNumber operator*(RationalNumber const& o) const;
RationalNumber operator/(RationalNumber const& o) const;
//输出流运算符重载
friend std::ostream &operator<<(std::ostream &os, RationalNumber const& o);
};
//有理数类每个方法的实现
_sint64 RationalNumber::calcGCD(_sint64 a, _sint64 b)
{
if (b == 0)
{
return a;
} /
/辗转相除法
return calcGCD(b, a % b);
} R
ationalNumber::RationalNumber(_sint64 numerator, _sint64 denominator)
{
m_negative = false;
m_infinate = false;
//处理分母为零的情况
if (denominator == 0)
{
m_infinate = true;
return;
} /
/这里这样写，是因为在通过计算结果进行构造过程中，有可能出现分子分母均为负的情况。
if (numerator < 0)
{
m_negative = !m_negative;
} i
f (denominator < 0)
{
m_negative = !m_negative;
} /
/计算整数、分子、分母。其中分母要参与下面的运算，所以不能是负的，用abs取绝对值，分子要保留
原值
m_integer = numerator / denominator;m_numerator = numerator - m_integer * denominator;
m_denominator = abs(denominator);
//约分，注意传给子函数的分子必须是正的，分母上面处理过了
if (m_numerator)
{
_sint64 maxtmp = calcGCD(abs(m_numerator), m_denominator);
if (maxtmp)
{
m_numerator /= maxtmp;
m_denominator /= maxtmp;
}
} /
/计算约分后假分数版的分子，因为后续运算是不需要整数部分的，所以必须用假分数的分子算。
m_numeratorAll = m_numerator + m_integer * m_denominator;
} /
/以下为分数的加减乘除，统统使用m_numeratorAll（假分数的分子）进行运算。
RationalNumber RationalNumber::operator+(RationalNumber const& o) const
{
_sint64 numerator = (m_numeratorAll * o.m_denominator) +
(o.m_numeratorAll * m_denominator);
_sint64 denominator = m_denominator * o.m_denominator;
return RationalNumber(numerator, denominator);
} R
ationalNumber RationalNumber::operator-(RationalNumber const& o) const
{
_sint64 numerator = (m_numeratorAll * o.m_denominator) -
(o.m_numeratorAll * m_denominator);
_sint64 denominator = m_denominator * o.m_denominator;
return RationalNumber(numerator, denominator);
} R
ationalNumber RationalNumber::operator*(RationalNumber const& o) const
{
_sint64 numerator = m_numeratorAll * o.m_numeratorAll;
_sint64 denominator = m_denominator * o.m_denominator;
return RationalNumber(numerator, denominator);
} R
ationalNumber RationalNumber::operator/(RationalNumber const& o) const
{
_sint64 numerator = m_numeratorAll * o.m_denominator;
_sint64 denominator = m_denominator * o.m_numeratorAll;
return RationalNumber(numerator, denominator);
} s
td::ostream &operator<<(std::ostream &os, RationalNumber const& o)
{
//分母为0的情况就不用继续了
if (o.m_infinate){
os << "Inf";
return os;
} /
/整数和分子为0那干脆就是0了
if (o.m_numerator == 0 && o.m_integer == 0)
{
os << "0";
return os;
} /
/负数打印括号和负号
if (o.m_negative)
{
os << "(-";
} /
/有整数就打整数
if (o.m_integer)
{
os << abs(o.m_integer);
if (o.m_numerator) //整数小数都有就打个空格隔开
{
os << " ";
}
} /
/有分数就打分数，分母已经abs过了，这里可以不用
if (o.m_numerator)
{
os << abs(o.m_numerator) << '/' << o.m_denominator;
} /
/负数的后半边括号
if (o.m_negative)
{
os << ")";
} r
eturn os;
} i
nt main()
{
_sint64 n1, d1, n2, d2;
scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
RationalNumber rn1(n1, d1), rn2(n2, d2);
//轻松+愉快的使用函数时间
std::cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << '\n';
std::cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << '\n';
std::cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << '\n';
std::cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << '\n';
return 0;
}