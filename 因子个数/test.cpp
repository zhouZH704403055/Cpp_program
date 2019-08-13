#
include <iostream>
#include<math.h>
using namespace std;
int main()
{int n,k,i;
while(cin >> n){
k=0;
for(i = 2; i <= sqrt(n); i++) {
if ((n % i) == 0) {
while((n % i) == 0){
n=n/i;
} k
++;
}
} i
f(n!=1)
k++;
cout<<k<<endl;
} r
eturn 0;
}