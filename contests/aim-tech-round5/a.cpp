#include <bits/stdc++.h>
using namespace std;
int n,m,minx,maxx,miny,maxy;
char a[120][120];
int main() {
    minx = 1e9;
    miny = 1e9;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf(" %s",a[i]+1);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j]=='B') {
                minx = min(minx,j);
                maxx = max(maxx,j);
                miny = min(miny,i);
                maxy = max(maxy,i);
            }
        }
    }
    printf("%d %d\n",(miny+maxy)/2,(minx+maxx)/2);
    return 0;
}