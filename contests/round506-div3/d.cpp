#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n,k,a,d,md,U,L,wa,ans;
vector <LL> v1;
vector <LL> v2[15];

LL dg(LL k) {
    LL cn = 0;
    while(k > 0) {
        k /= 10;
        cn++;
    }
    return cn;
}
LL pot(LL k) {
    LL x = 1;
    for(LL i = 0; i < k; i++) x*=10;
    return x;
}
LL sorter(LL x,LL y) {
    return (x % k) < (y % k);
}
int main() {
    scanf("%lld %lld",&n,&k);
    for(LL i = 0; i < n; i++) {
        scanf("%lld",&a);
        v1.push_back(a);
        d = dg(a);
        v2[d].push_back(a);
    }
    for(LL i = 1; i <= 10; i++) {
        sort(v2[i].begin(), v2[i].end(),sorter);
    }
    for(LL i = 0; i < n; i++) {
        for(LL j = 1; j <= 10; j++) {
            md = ((pot(j) % k)*(v1[i] % k)) % k;
            wa = (k - md);
            U = upper_bound(v2[j].begin(),v2[j].end(),wa,sorter)-v2[j].begin();
            L = lower_bound(v2[j].begin(),v2[j].end(),wa,sorter)-v2[j].begin();
            ans += U - L;
        }
        if(((v1[i]%k)*(pot(dg(v1[i]))%k)+(v1[i]%k))%k==0) {
            ans--;
        }
    }
    printf("%lld\n",ans);
    return 0;
}