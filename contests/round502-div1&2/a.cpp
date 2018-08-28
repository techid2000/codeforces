#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,n,tmp;
int ar[1005];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a>>b>>c>>d;
        ar[i]=a+b+c+d;
    }
    tmp=ar[1];
    sort(ar+1,ar+1+n,greater<int>());
    for(int i=1;i<=n;i++) {
        if(ar[i]==tmp) {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}