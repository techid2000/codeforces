#include <bits/stdc++.h>
using namespace std;
int n,a[150005],b[150005],j;
set<int>un;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d%d",a+i,b+i);
    }
    j = sqrt(a[0]);
    for(int i=2; i<=j; i++) {
        if(a[0]%i == 0) {
            un.insert(i);
            while(a[0]%i==0) {
                a[0]/=i;
            }
        }
    }
    if(a[0]!=1) un.insert(a[0]);
    j = sqrt(b[0]);
    for(int i=2; i<=j; i++) {
        if(b[0]%i == 0) {
            un.insert(i);
            while(b[0]%i==0) {
                b[0]/=i;
            }
        }
    }
    if(b[0]!=1) un.insert(b[0]);
    for(auto k : un) {
        for(j=1; j<n; j++) {
            if(a[j]%k != 0 && b[j]%k != 0) {
                break;
            }
        }
        if(j==n) {
            printf("%d\n",k);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}