#include <bits/stdc++.h>
using namespace std;
struct rect {
    int x1, y1;
    int x2, y2;
    int none;
};

rect intersect(rect* r1, rect* r2) {
    int f1,f2;
    f1 = f2 = 0;
    rect ret; ret.none = 1;
    if(r1->none || r2->none) return ret;
    if(r1->x1 <= r2->x1 && r1->x2 >= r2->x1) 
        f1 = 1, ret.x1 = r2->x1, ret.x2 = min(r1->x2,r2->x2);
    if(r1->x1 >= r2->x1 && r2->x2 >= r1->x1) 
        f1 = 1, ret.x1 = r1->x1, ret.x2 = min(r1->x2,r2->x2);
    if(r1->y1 <= r2->y1 && r1->y2 >= r2->y1) 
        f2 = 1, ret.y1 = r2->y1, ret.y2 = min(r1->y2,r2->y2);
    if(r1->y1 >= r2->y1 && r2->y2 >= r1->y1)
        f2 = 1, ret.y1 = r1->y1, ret.y2 = min(r1->y2,r2->y2);
    if(f1&&f2) {
        ret.none = 0;
        return ret;
    } else {
        return ret;
    }
}
int n;
rect r[200000];
rect L[200000];
rect R[200000];
rect tmp;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);
        r[i].none = 0;
        L[i].none = 1;
        R[i].none = 1;
    }
    L[1]=r[1];
    R[n]=r[n];
    for(int i=2;i<=n;i++)
        L[i]=intersect(&r[i],&L[i-1]);
    for(int i=n-1;i>=1;i--)
        R[i]=intersect(&r[i],&R[i+1]);
    if(L[n-1].none==0) {
        printf("%d %d\n",L[n-1].x1,L[n-1].y1);
        return 0;
    }
    if(R[2].none == 0) {
        printf("%d %d\n",R[2].x1,R[2].y1);
        return 0;
    }
    for(int i=2;i<=n-1;i++) {
        tmp = intersect(&L[i-1],&R[i+1]);
        if(tmp.none == 0) {
            printf("%d %d\n",tmp.x1,tmp.y1);
            return 0;
        }
    }
    return 0;
}