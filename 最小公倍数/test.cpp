#
include<iostream>
using namespace std;
int gcd(int a, int b)
{
int r;
while(r = a%b){
a = b;
b = r;
} r
eturn b;
} i
nt main()
{
int a,b;
while(cin >> a >> b){
cout << a*b/gcd(a,b) <<endl;
} r
eturn 0;
}