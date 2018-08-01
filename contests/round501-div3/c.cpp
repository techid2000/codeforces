#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>v;
long long opt,n,m,a,b,diff,cnt;
int main()
{
    scanf("%lld%lld",&n,&m);
    cnt = n;
    for(long long i=0; i<n; i++) {
        scanf("%lld%lld",&a,&b);
        v.push_back({a,b});
        opt += b;
    }
    if(opt > m) {
        printf("-1\n");
        return 0;
    }
    sort(v.begin(),v.end(),[](auto a, auto b) -> bool{
        return (a.first-a.second) < (b.first-b.second);
    });
    for(long long i=0; i<v.size(); i++) {
        diff = v[i].first-v[i].second;
        if(opt + diff <= m) {
            opt += diff;
            cnt--;
        } 
    }
    printf("%lld\n",cnt);
    return 0;
}