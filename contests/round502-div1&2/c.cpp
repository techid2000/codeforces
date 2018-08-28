//hard to prove
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    int n,block;
    scanf("%d",&n);
    block = sqrt(n);
    for(int i=1; i<=n; i++) {
        a[i] = i;
    }
    for(int i=1; i<=n; i+=block) {
        sort(a+i,a+i+block,greater<int>());
    }
    for(int i=1; i<=n; i++) {
        printf("%d ",a[i]);
    }
}