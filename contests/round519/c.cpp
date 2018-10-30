#include <bits/stdc++.h>
using namespace std;
char a[1005];
int mark[1005];
int n,i;
int main() {
    scanf(" %s",a);
    n=strlen(a);
    for(i=0;i<n;i++) {
        if((i==n-1 && a[i]=='a') || (i<n-1 && a[i]!=a[i+1])) {
            mark[i]=1;
        }
    }
    for(i=0;i<n;i++) {
        printf("%d ",mark[i]);
    }
    return 0;
}