//Author: techid2000
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a) for(int i=0;i<a;i++)
#define PII pair<int,int>
#define LL long long
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
using namespace std;

int n;
PII l[100005];
PII r[100005];
int pre[100005];
int counted[100005];
LL sum;

int cmp(PII a, PII b) {
    return a.Y < b.Y;
}

void dfs(int x, int y) {
    counted[x] = 1;
    sum += max(l[x].X, r[pre[x]].X);
    if(!counted[pre[x]]) {
        dfs(pre[x], y+1);
    } else {
        sum += y;
    }
}

int main() {
    //Code here
    scanf("%d", &n);
    foru(i, 1, n+1) {
        scanf("%d %d",&l[i].X,&r[i].X);
        l[i].Y = r[i].Y = i;
    }
    sort(r+1, r+1+n);
    sort(l+1, l+1+n);
    foru(i, 1, n+1) {
        pre[l[i].Y] = r[i].Y;
    }
    sort(r+1, r+1+n, cmp);
    sort(l+1, l+1+n, cmp);
    foru(i, 1, n+1) {
        if(!counted[i]) {
            dfs(i, 1);
        }
    }
    printf("%lld\n",sum);
    return 0;
}