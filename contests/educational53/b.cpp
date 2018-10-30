#include <bits/stdc++.h>
using namespace std;

int n,j=1;
int out[200005];
int a[200005];
int b,t;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&b);
        if(out[b]) {
            printf("0 ");
        } else {
            t=1;
            while(a[j]!=b) {
                out[a[j]]=1;
                j++, t++;
            }
            printf("%d ",t);
            j++;
        }
    }
    return 0;
}