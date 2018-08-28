#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int want;
long long best,cost;
vector <int> p[3005];
int main() {
    scanf ("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d%d",&a,&b);
        p[a].push_back(b);
    }
    for(int i=2; i<=m; i++) {
        sort(p[i].begin(),p[i].end());
    }
    best = LLONG_MAX;
    for(int v=1; v<=n; v++) {
        want = v - p[1].size();
        cost = 0;
        vector<int> remain;
        for(int i=2; i<=m; i++) {
            for(int j=0; j<(int)p[i].size()-(v-1); j++) {
                want--;
                cost += p[i][j];
            }
            for(int j=max((int)p[i].size()-(v-1),0); j<(int)p[i].size(); j++) {
                remain.push_back(p[i][j]);
            }
        }
        if(want > 0) {
            nth_element(remain.begin(),remain.begin()+want,remain.end());
            for(int i=0; i<want; i++) {
                cost += remain[i];
            }
        }
        best = min(best, cost);
    }
    printf("%lld\n",best);
    return 0;
}