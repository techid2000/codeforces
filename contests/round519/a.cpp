#include <bits/stdc++.h>
using namespace std;

int n,s,ss,ma,i,j;
int a[105];

int main() {
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        s+=a[i];
        ma=max(ma,a[i]);
    }
    for(i=ma;i<=1000;i++) {
        ss = 0;
        for(j=1;j<=n;j++)
            ss+=i-a[j];
        if(ss>s){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}