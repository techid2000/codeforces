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
LL a[100005],n,m,s,r;
int main() {
    //Code here
    scanf("%lld%lld",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%lld",a+i);
        s+=a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++) {
        cnt++;
        if(i==n-1 || a[i+1]!=a[i]) {
            s+=cnt*a[i]-max(cnt,a[i]-past);
            if(i<n-1) ss+=a[i+1]-a[i];
            past=a[i];
            cnt=0;
        }
    }
    printf("%lld\n",s);
    return 0;
}