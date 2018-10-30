#include <bits/stdc++.h>
using namespace std;

int n,i;
char str[200005];
int x,y;
int sx,sy,bx,by,wx,wy,rx,ry;
int lo,hi,mid;
int ans,am;
int main() {
    scanf("%d",&n);
    scanf(" %s",str+1);
    scanf("%d%d",&x,&y);
    for(i=1;i<=n;i++) {
        if(str[i]=='R') sx++;
        if(str[i]=='L') sx--;
        if(str[i]=='U') sy++;
        if(str[i]=='D') sy--;
    }
    lo=0, hi=n;
    ans=-1;
    while(lo<=hi) {
        mid=(lo+hi)>>1;
        bx=0, by=0;
        for(i=1;i<=mid-1;i++) {
            if(str[i]=='R') bx++;
            if(str[i]=='L') bx--;
            if(str[i]=='U') by++;
            if(str[i]=='D') by--;
        }
        for(i=mid;i<=n;i++) {
            if(str[i-mid]=='R') bx--;
            if(str[i-mid]=='L') bx++;
            if(str[i-mid]=='U') by--;
            if(str[i-mid]=='D') by++;
            if(str[i]=='R') bx++;
            if(str[i]=='L') bx--;
            if(str[i]=='U') by++;
            if(str[i]=='D') by--;
            rx=sx-bx, ry=sy-by;
            wx=x-rx, wy=y-ry;
            am = abs(wx)+abs(wy);
            if(am<=mid && (mid-am)%2==0) {
                ans=mid;
                hi=mid-1;
                break;
            }
        }
        if(i>n){
            lo=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}