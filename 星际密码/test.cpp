#include <iostream>
#include <vector>
std::vector<int> a = {1,1};
void data_init()
{
int i;
for(i=2;i<10005;i++){
a.push_back((a[i-1]+a[i-2]) % 10000);
}
} i
nt main()
{
int n,t;
data_init();
while(std::cin >> n){
while(n--){
std::cin >> t;
printf("%04d",a[t])
} p
rintf("\n");
} r
eturn 0;
}