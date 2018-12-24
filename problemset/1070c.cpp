#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a) for(int i=0;i<a;i++)
#define PII pair<int,int>
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
using namespace std;

vector <PII> v;
priority_queue < minheap(PII) > in,out;
long long fen[1000005],fen2[1000005];

void add(long long i,long long x,long long y) {
    while(i < 1000005) {
        fen[i] += x;
        fen2[i] += y;
        i += (i & (-i));
    }
}
long long que(long long i) {
    long long sum = 0;
    while(i > 0) {
        sum += fen[i];
        i -= (i & (-i));
    }
    return sum;
}
long long que2(long long i) {
    long long sum = 0;
    while(i > 0) {
        sum += fen2[i];
        i -= (i & (-i));
    }
    return sum;
}

long long n,k,m,l,r,c,p,id;
long long lo,hi,mid,ans,ans2;
long long sum,cost;

int main() {
    scanf("%lld%lld%lld",&n,&k,&m);
    rep(i,m) {
        scanf("%lld%lld%lld%lld",&l,&r,&c,&p);
        in.push({l, i});
        out.push({r, i});
        v.push_back({c, p});
    }
    foru(day, 1, n+1) {
        while(!out.empty() && out.top().X+1 <= day) {
            id = out.top().Y;
            add(v[id].Y,-1ll*v[id].X*v[id].Y,-v[id].X);
            // printf("on the day %lld; popped %lld\n",day,out.top().Y);
            out.pop();
        }
        while(!in.empty() && in.top().X <= day) {
            id = in.top().Y;
            add(v[id].Y,1ll*v[id].X*v[id].Y,v[id].X);
            // printf("Added %lld with %lld\n",v[id].Y,v[id].X);
            // printf("on the day %lld; pushed %lld\n",day,in.top().Y);
            in.pop();
        }
        // printf("%lld\n",que(1000000));
        lo=1, hi=1000000,ans=ans2=-1;
        while(lo<=hi) {
            mid = (lo+hi) >> 1;
            if(que2(mid) >= k) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
                ans2 = mid;
            }
        }
        // printf(";%lld\n",ans);
        if(ans==-1) ans=ans2;
        cost = 1ll*que(ans);
        if(que2(ans) > k) {
            cost -= 1ll*ans*(que2(ans)-k);
        }
        // printf("%lld;%lld == %lld\n",day,cost,mid);
        sum += cost;
    }
    printf("%lld\n",sum);
    return 0;
}