#include <bits/stdc++.h>
using namespace std;

int n,k,j;
int pf[55];
char s[55];
int main() {
    scanf("%d %d",&n,&k);
    scanf(" %s",s+1);
    pf[1] = j = 0;
    for(int i=2;i<=n;i++) {
        while(j > 0 && s[j+1] != s[i]) {
            j = pf[j];
        }
        if(s[j+1] == s[i]) j++;
        pf[i] = j;
    }
    printf("%s",s+1);
    for(int i=0;i<k-1;i++) {
        printf("%s",&s[pf[n]+1]);
    }
}