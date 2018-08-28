#include <bits/stdc++.h>
using namespace std;
long long n,k,lo,hi,mid,ans;
int main() {
    scanf("%lld%lld",&n,&k);
    lo = 0, hi = (k-1)/2;
    while(lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if(k-mid <= n && mid <= n) {
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    printf("%lld\n",(k-1)/2 - lo);
}