#include <bits/stdc++.h>
using namespace std;

int n;
char a[1000005];
char b[1000005];
int ans,con;
int main() {
    scanf("%d",&n);
    scanf(" %s %s",a,b);
    for(int i=0;i<n;i++) {
        if(a[i]!=b[i] && (i==0 || a[i]!=a[i-1])) {
            con++;
        } else {
            ans += ceil(1.0*con/2);
            if(a[i]!=b[i]) {
                con=1;
            } else {
                con=0;
            }
        }
    }
    ans += ceil(1.0*con/2);
    printf("%d\n",ans);
    return 0;
}