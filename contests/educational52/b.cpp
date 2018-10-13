#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,m,i;
    scanf("%lld%lld",&n,&m);
    for(i=0; i<=n; i++) {
        if(i*(i-1)/2 >= m) break;
    }
    printf("%lld %lld",2*m>=n?0:n-2*m,n-i);
    return 0;
}