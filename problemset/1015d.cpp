#include <bits/stdc++.h>
#define say(x) printf(x)

typedef long long ll;
using namespace std;
ll n,k,s,p,q,a,b,pos;
inline void setpos(int x) {
    if(pos + x <= n) pos += x;
    else if(pos - x >= 1) pos -= x;
    printf("%d ",pos);
}
int main()
{
    scanf("%lld%lld%lld",&n,&k,&s);
    p = (ll)ceil((double)s/k);
    q = (ll)floor((double)s/k);
    pos = 1;
    if(n-1 < p || k > s) {
        printf("NO\n");
    } else {
        printf("YES\n");
        b = s - q*k;
        a = k - b;
        for(int i=0; i<b; i++)
            setpos(p);
        for(int i=0; i<a; i++)
            setpos(q);
    }
    return 0;
}