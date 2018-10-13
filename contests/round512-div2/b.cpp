#include <bits/stdc++.h>
using namespace std;

int n,d,m,x,y;

int main() {
    scanf("%d%d",&n,&d);
    scanf("%d",&m);
    while(m--) {
        scanf("%d%d",&x,&y);
        if(y > x+d || y < x-d || y > -x+2*n-d || y < d-x) {
            printf("no\n");
        } else {
            printf("yes\n");
        }
    }
    return 0;
}