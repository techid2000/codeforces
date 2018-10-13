#include <bits/stdc++.h>
using namespace std;

int n,k,h;
int ma = 0;
int mi = 1e9;
int roam[200005];
int s,i,t;

int main() {
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++) {
        scanf("%d",&h);
        roam[1]++;
        roam[h+1]--;
        ma = max(ma, h);
        mi = min(mi, h);
    }
    if(mi==ma) {
        printf("0\n");
        return 0;
    }
    for(i=1;i<=ma;i++) roam[i]+=roam[i-1];
    for(i=mi+1;i<=ma;i++) {
        if(s+roam[i]>k) {
            t++;
            if(roam[i]>k) {
                break;
            }
            s=roam[i];
        } else {
            s+=roam[i];
        }
    } t++;
    printf("%d\n",t);
    return 0;
}