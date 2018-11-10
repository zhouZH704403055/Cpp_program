#include"Date.h"

int Date::GetMonthDay(int year, int month)
{
	static int dayofmonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)))
	{
		return 29;
	}
	return dayofmonth[month - 1];
}

Date::Date(int year, int month, int day)
{
	if ((year >= 0) && (month >= 1) && (month <= 12) && (day > 0) && (day <= GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "´íÎóÈÕÆÚ£¡£¡£¡" << endl;
	}
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(const Date& d)
{
	if ((_year == d._year) && (_month == d._month) && (_day == d._day))
	{
		return true;
	}
	return false;
}
bool Date::operator<(const Date& d)
{
	return !((*this) == d || (*this) > d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date Date::operator+(int day)
{
	Date ret(*this);
	ret._day += day;
	if (ret._day > GetMonthDay(_year, _month))
	{
		day = ret._day;
		ret._day = 0;
		while (day > GetMonthDay(ret._year, ret._month))
		{
			day -= GetMonthDay(ret._year, ret._month);
			if (ret._month == 12)
			{
				ret._year++;
				ret._month = 1;
				ret._day = 1;
			}
			else
			{
				ret._month++;
				ret._day = 1;
			}
		}
		ret._day = day;
	}
	return ret;
}
Date& Date::operator+=(int day)
{
	this->_day += day;
	if (_day > GetMonthDay(_year, _month))
	{
		day = _day;
		while (day > GetMonthDay(_year, _month))
		{
			day -= GetMonthDay(_year, _month);
			if (_month == 12)
			{
				_year++;
				_month = 1;
				_day = 1;
			}
			else
			{
				_month++;
				_day = 1;
			}
		}
		_day = day;
	}
	return (*this);
}

Date Date::operator-(int day)
{
	Date ret(*this);
	while (ret._day <= day)
	{
		day -= ret._day;
		if (ret._month == 1)
		{
			ret._year--;
			ret._month = 12;
			ret._day = 31;
		}
		else
		{
			ret._month--;
			ret._day = GetMonthDay(ret._year, ret._month);
		}
	}
	ret._day -= day;
	return ret;
}

Date& Date::operator-=(int day)
{
	while (_day <= day)
	{
		day -= _day;
		if (_month == 1)
		{
			_year--;
			_month = 12;
			_day = 31;
		}
		else
		{
			_month--;
			_day = GetMonthDay(_year, _month);
		}
	}
	_day -= day;
	return (*this);
}

int Date::operator-(const Date& d)
{
	int day = 0;
	if (*this == d)
	{
		return 0;
	}
	else if (*this < d)
	{
		int i = 0;
		day = GetMonthDay(this->_year, this->_month) - this->_day;
		day += d._day;
		for (i = 0; i < 12 - (this->_month); i++)
		{
			day += GetMonthDay(this->_year, this->_month + i + 1);
		}
		for (i = 1; i < d._month; i++)
		{
			day += GetMonthDay(d._year, i);
		}
		for (i = this->_year + 1; i < d._year; i++)
		{
			if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
			{
				day += 366;
			}
			else
			{
				day += 365;
			}
		}
	}
	else
	{
		int i = 0;
		day = GetMonthDay(d._year, d._month) - d._day;
		day += this->_day;
		for (i = 0; i < 12 - (d._month); i++)
		{
			day += GetMonthDay(d._year, d._month + i + 1);
		}
		for (i = 1; i < this->_month; i++)
		{
			day += GetMonthDay(this->_year, i);
		}
		for (i = d._year + 1; i < this->_year; i++)
		{
			if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
			{
				day += 366;
			}
			else
			{
				day += 365;
			}
		}
	}
	return day;
}

int main()
{
	Date d1(2019, 12, 22);
	Date d2(2017, 11, 11);
	int day = d2 - d1;
	return 0;
}