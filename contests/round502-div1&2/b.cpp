#include <bits/stdc++.h>
using namespace std;
int n,z,o;
long long cnt;
char a[100005],b[100005];
int main() {
    scanf("%d",&n);
    scanf(" %s %s",a,b);
    for(int i=0;i<n;i++) {
        if(a[i]=='0') z++;
    }
    o=n-z;
    for(int i=0;i<n;i++) {
        if(b[i]=='0') {
            if(a[i]=='0') cnt+=o,z--;
            else cnt+=z,o--;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}