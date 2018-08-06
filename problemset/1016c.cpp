#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 300005;

int n;
ll a[N],b[N];
ll qsa[N],qsb[N];
ll dp1[N],dp2[N];
ll maxx;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) 
        cin >> a[i];
    for(int i=1;i<=n;i++) 
        cin >> b[i];
    for(int i=1;i<=n;i++) {
        if(i%2==1)
            dp1[i] = dp1[i-1]+(2*i-2)*a[i]+(2*i-1)*b[i];
        else
            dp1[i] = dp1[i-1]+(2*i-2)*b[i]+(2*i-1)*a[i];
    }
    for(int i=n;i>=1;i--) {
        qsa[i]=qsa[i+1]+a[i],qsb[i]=qsb[i+1]+b[i];
        if(i%2==1) {
            dp2[i] = dp2[i+2] + (2*i-2)*a[i]+(2*i-1)*a[i+1] + (2*n-1)*b[i]+(2*n-2)*b[i+1] - 2*(qsa[i+2]+qsb[i+2]);
        } else {
            dp2[i] = dp2[i+2] + (2*i-2)*b[i]+(2*i-1)*b[i+1] + (2*n-1)*a[i]+(2*n-2)*a[i+1] - 2*(qsa[i+2]+qsb[i+2]);
        }
    } 
    for(int i=0;i<=n;i++) {
        maxx = max(maxx, dp1[i]+dp2[i+1]);
    }
    printf("%lld\n",maxx);
    return 0;
}