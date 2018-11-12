#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class String
{
public:
	String(const char* p = "");
	String(const String& s);
	~String();
	String& operator=(String s);
	String& operator=(const String& s);
	char& operator[](size_t pos);
	const char& operator[](size_t pos) const;
	size_t Size() const;
	size_t Capacity() const;
	void Swap(String& s);

	String& operator+=(const char ch);
	String& operator+=(const char* str);
	size_t Find(char ch, size_t pos = 0);
	size_t Find(const char* str, size_t pos = 0);
	void PushBack(const char ch);
	void Append(const char* str);
	void Insert(size_t pos, char ch);
	void Insert(size_t pos, const char* str);
	void Erase(size_t pos, size_t len = npos);
	void Reserve(size_t n);
	void Resize(size_t n, char ch = '\0');
private:
	char* _str;
	size_t _size;
	size_t _capacity;
	static const size_t npos;
};
const size_t String::npos = -1;
