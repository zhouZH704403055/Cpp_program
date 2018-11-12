#define _CRT_SECURE_NO_WARNINGS
#include"String.h"
String::String(const char* p = "")
	:_str(new char[strlen(p)+1]),_size(strlen(p)),_capacity(_size)
{
	strcpy(_str, p);
}

String::String(const String& s)
	:_str(nullptr),_size(0),_capacity(0)
{
	String tmp(s._str);
	this->Swap(tmp);
}

String::~String()
{
	delete[] _str;
	_str = nullptr;
	_size = 0;
	_capacity = 0;
}

String& String::operator=(String s)
{
	swap(_str, s._str);
	return *this;
}

//String& String::operator=(const String& s)
//{
//	if (this == &s)
//	{
//		return *this;
//	}
//	delete[] _str;
//	_str = new char[strlen(s._str) + 1];
//	strcpy(_str, s._str);
//	return *this;
//}

String& String::operator=(const String& s)
{
	if (this != &s)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}
	return *this;
}

void String::Swap(String& s)
{
	swap(_str,s._str);
	swap(_size, s._size);
	swap(_capacity, s._capacity);
}

void String::Reserve(size_t n)
{
	if (n > _capacity)
	{
		const char* str = _str;
		_str = new char[n+1];
		_capacity = n;
		strcpy(_str, str);
		delete[] str;
	}
}

void String::Resize(size_t n, char ch = '\0')
{
	if (n < _size)
	{
		_str[n] = '\0';
	}
	else
	{
		if (n > _capacity)
		{
			Reserve(n);
		}
		for (int i = _size; i < n; i++)
		{
			_str[i] = '\0';
		}
	}
	_size = n;
}

void String::PushBack(const char ch)
{
	if (_size == _capacity)
	{
		Reserve(2 * _capacity);
	}
	_str[_size] = ch;
	_size++;
	_str[_size] = '\0';
}

void String::Append(const char* str)
{
	size_t len = strlen(str);
	if (_capacity < _size + len)
	{
		Reserve(_size + len + 1);
	}
	strcat(_str, str);
	_size += len;
}

char& String::operator[](size_t pos)
{
	return _str[pos];
}

const char& String::operator[](size_t pos) const
{
	return _str[pos];
}

size_t String::Size() const
{
	return _size;
}
size_t String::Capacity() const
{
	return _capacity;
}

String& String::operator+=(const char ch)
{
	this->PushBack(ch);
	return *this;
}

String& String::operator+=(const char* str)
{
	this->Append(str);
	return *this;
}

size_t String::Find(char ch, size_t pos = 0)
{
	for (int i = pos; i < _size; i++)
	{
		if (_str[i] == ch)
		{
			return i;
		}
	}
	return npos;
}


int main()
{
	return 0;
}