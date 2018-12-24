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
LL q,a,b,oa,ob,ea,eb,no,ne;
LL so,se;
int main() {
    scanf("%lld",&q);
    while(q--) {
        scanf("%lld%lld",&a,&b);
        if(a%2==1)oa=a,ea=a+1;
        else oa=a+1,ea=a;
        if(b%2==1)ob=b,eb=b-1;
        else ob=b-1,eb=b;
        no=(ob-oa)/2+1, ne=(eb-ea)/2+1;
        so=-(no*(oa+ob))/2, se=(ne*(ea+eb))/2;
        printf("%lld\n",so+se);
    }
    //Code here
    return 0;
}