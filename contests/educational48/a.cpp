#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a;
ll c;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d",&a);
        printf("%lld ",(c+a)/m - c/m);
        c += a;
    }
    return 0;
}