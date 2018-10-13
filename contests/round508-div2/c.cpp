#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n;
LL a[100005];
LL b[100005];
LL pa,pb;
LL sa,sb;
LL turn;
int main() {
    scanf("%lld",&n);
    for(LL i=0;i<n;i++)scanf("%lld",a+i);
    for(LL i=0;i<n;i++)scanf("%lld",b+i);
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    // for(LL i=0;i<n;i++) {
    //     printf("%d ",a[i]);
    // }printf("\n");
    // for(LL i=0;i<n;i++) {
    //     printf("%d ",b[i]);
    // }
    while(pa<n && pb<n) {
        if(turn==0) {
            if(a[pa]>b[pb]) {
                sa += a[pa];
                pa++;
                // printf("A get\n");
            } else {
                // printf("A hub\n");
                pb++;
            }
            turn=1;
        } else {
            if(b[pb]>a[pa]) {
                // printf("B get\n");
                sb += b[pb];
                pb++;
            } else {
                // printf("B hub\n");
                pa++;
            }
            turn=0;
        }
    }
    while(pa<n) {
        if(turn==0){
            sa+=a[pa];
            pa++;
            turn=1;
            // printf("A get\n");
        } else {
            // printf("B hub\n");
            pa++;
            turn=0;
        }
    }
    while(pb<n) {
        if(turn==1) {
            sb+=b[pb];
            pb++;
            turn=0;
            // printf("B get\n");
        } else {
            pb++;
            turn=1;
            // printf("A hub\n");
        }
    }
    printf("%lld\n",sa-sb);
    return 0;
}