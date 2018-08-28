#include <bits/stdc++.h>
using namespace std;
int n,cn,an;
int a[200005];
int main() {
    scanf("%d",&n);
    an = 1;
    for(int i=1;i<=n;i++) {
        scanf("%d",a+i);
        if(a[i] <= a[i-1]*2) {
            cn++;
            an = max(an,cn);
        } else {
            cn = 1;
        }
    }
    printf("%d\n",an);
}