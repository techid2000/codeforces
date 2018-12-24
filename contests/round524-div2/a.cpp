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
LL n,k,s;
int main() {
    //Code here
    scanf("%lld%lld",&n,&k);
    s+=(2*n)/k;
    if((2*n)%k>0)s++;
    s+=(5*n)/k;
    if((5*n)%k>0)s++;
    s+=(8*n)/k;
    if((8*n)%k>0)s++;
    printf("%lld\n",s);
    return 0;
}