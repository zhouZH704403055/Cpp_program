#include<iostream>

using namespace std; 

class Shape
{
public:
	virtual double area() = 0;
};

double total(Shape* s[], int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += s[i]->area();
	}
	return sum;
}

class Circle :public Shape
{
public:
	Circle(double r):radius(r){}
	void set_radius(double r)
	{
		radius = r;
	}
	void show()
	{
		cout << radius << endl;
	}
	virtual double area()
	{
		return 3.14*radius*radius;
	}
private:
	double radius;
};

class Square :public Shape
{
public:

	Square(double n):a(n){}
	void set_a(double n)
	{
		a = n;
	}
	void show()
	{
		cout << a << endl;
	}
	virtual double area()
	{
		return a * a;
	}
private:
	double a;
};

int main()
{
	Circle c(5.5);
	Square s(9.9);
	Shape* array[2] = { &c,&s };
	int n = 2;
	int sum = total(array, n);
	cout << sum << endl;
	return 0;
}