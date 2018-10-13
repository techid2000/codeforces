#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,lo,hi,mid,fail,ans;
LL x[100005],y[100005];

int main() {
    scanf("%lld",&n);
    for(LL i=0;i<n;i++)
        scanf("%lld%lld",&x[i],&y[i]);
    lo=1, hi=INT_MAX;
    while(lo<=hi) {
        mid=(lo+hi)/2;
        fail=0;
        for(LL i=0;i<n;i++) {
            if(y[i] > -x[i]+mid) {
                fail=1;
                break;
            }
        }
        if(!fail) {
            ans = mid;
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }
    printf("%lld\n",ans);
}