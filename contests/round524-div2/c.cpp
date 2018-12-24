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

LL numOdd(LL a,LL b) {
    if(a%2==0)a++;
    if(b%2==0)b--;
    return (b-a)/2+1ll;
}
LL numEven(LL a,LL b) {
    if(a%2==1)a++;
    if(b%2==1)b--;
    return (b-a)/2+1ll;
}
LL overlap(LL a1,LL b1,LL a2, LL b2) {
    if(b1 < a2 || b2 < a1) return false;
    return true;
}
pair<LL,LL> numWB(LL a,LL b,LL c,LL d) {
    LL nb = numEven(a,c)*numOdd(b,d)+numOdd(a,c)*numEven(b,d);
    LL nw = (abs(a-c)+1)*(abs(b-d)+1)-nb;
    // printf(">>> %lld,%lld; %lld,%lld\n",numEven(a,b),numOdd(c,d),numOdd(a,b),numEven(c,d));
    return make_pair(nw,nb);
}
LL n,m,t;
LL x1,yy1,x2,y2;
LL x3,y3,x4,y4;
LL X1,Y1,X2,Y2,ox,oy;
LL black,white,B,W;
pair<LL,LL> all,sw,sb,sm;

int main() {
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld%lld",&n,&m);
        scanf("%lld%lld%lld%lld",&x1,&yy1,&x2,&y2);
        scanf("%lld%lld%lld%lld",&x3,&y3,&x4,&y4);
        all=numWB(1,1,n,m);
        ox=oy=0;
        if(x2>=x3 && x1<=x4) {
            X1=max(x1,x3);
            X2=min(x2,x4);
            ox=1;
        }
        if(y2>=y3 && yy1<=y4) {
            Y1=max(yy1,y3);
            Y2=min(y2,y4);
            oy=1;
        }  
        sw=numWB(x1,yy1,x2,y2);
        sb=numWB(x3,y3,x4,y4);
        white=all.X-sw.X-sb.X;
        black=all.Y-sw.Y-sb.Y;
        if(ox&&oy) {
            sm=numWB(X1,Y1,X2,Y2);
            white+=sm.X;
            black+=sm.Y;
        }
        // printf("t%lld %lld\n",white,black);
        W=(abs(x1-x2)+1)*(abs(yy1-y2)+1);
        if(ox&&oy) {
            W-=(abs(X1-X2)+1)*(abs(Y1-Y2)+1);
        }
        B=(abs(x3-x4)+1)*(abs(y3-y4)+1);
        // printf("db %lld %lld\n",W,B);
        printf("%lld %lld\n",white+W,black+B);
    }
    return 0;
}