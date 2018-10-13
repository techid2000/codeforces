#include <bits/stdc++.h>
using namespace std;
int t;
long long s,a,b,c;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%lld%lld%lld%lld",&s,&a,&b,&c);
        printf("%lld\n",s/c +((s/c)/a)*b);
    }
}