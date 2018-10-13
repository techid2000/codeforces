#include <bits/stdc++.h>
using namespace std;
int n,a,b,s;
int A[30];
int main() {
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++) {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++) {
        if(A[i]==2 && A[n-1-i]==2) {
            s+=min(a,b);
        } else if(A[i]==2) {
            s+=A[n-1-i]?b:a;
        } else if(A[n-1-i]!=2 && A[i]!=A[n-1-i]) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",s);
    return 0;
}