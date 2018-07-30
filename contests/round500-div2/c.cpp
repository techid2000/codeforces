#include <bits/stdc++.h>
using namespace std;

int n;
long long minn;
int a[200005];
int main()
{
    scanf("%d",&n);
    for(int i=0; i<2*n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a, a+2*n);
    minn = (long long)(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    for(int i=n; i<2*n-1; i++) {
        minn = min(minn, (long long)(a[2*n-1]-a[0])*(a[i]-a[i-n+1]));
    }
    printf("%lld\n",minn);
    return 0;
}