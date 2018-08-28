#include <bits/stdc++.h>
#define F first
#define S second
#define PII pair<int,int>
using namespace std;

int n,a,b,l1,l2,p,q,mx;
vector < PII > v;

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
        if(a > l1) l2 = l1, l1 = a;
        else if(a > l2) l2 = a;
    }
    sort(v.begin(),v.end(),[](PII x, PII y){
        return x.S < y.S;
    });
    for (int i = 0; i < n; i++) {
        q = (i == 0) ? v[1].S : v[0].S;
        p = (v[i].F == l1) ? l2 : l1;
        mx = max(mx, q - p); 
    }
    printf("%d\n",mx);
    return 0;
}