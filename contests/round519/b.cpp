#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,s;
int a[1005],b[1005],c[1005],cn;
int main() {
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    b[0]=a[0];
    for(i=1;i<n;i++)
        b[i]=a[i]-a[i-1];
    for(s=1;s<=n;s++) {
        for(j=0;j<n;j++) {
            if(b[j]!=b[j%s])
                break;
        }
        if(j==n){
            cn++;
            c[s]=1;
        }
    }
    printf("%d\n",cn);
    for(i=1;i<=n;i++) 
        if(c[i]) 
            printf("%d ",i);
    return 0;
}