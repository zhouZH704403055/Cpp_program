#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
long long n;int cnt;
while ((scanf("%lld",&n)) != EOF) {
	if (n == 0)
		break;
	cnt=0;
	while (n >= 2) {
		if (n % 3) {
			//不可以整除则取最差情况：最重的一份是 n/3 + 1个金币
			n=n/3+1;
	}else {
		//可以整除在直接整除，能够获取到最重的一份
		n/=3;
	} 
	cnt++;
	}
	printf("%d\n",cnt);
	};
	return 0;
}