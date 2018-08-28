#include <bits/stdc++.h>
using namespace std;

int n,m,i,j,p,q,st;
char s1[200005];
char s2[200005];
int main() {
    scanf("%d%d",&n,&m);
    scanf(" %s %s",s1,s2);
    for(int i=0; i<n; i++) {
        if(s1[i]=='*')
            st=1;
    }
    if(st==0) {
        if(!strcmp(s1,s2)) printf("YES\n");
        else printf("NO\n");
        return 0;
    } else {
        while(i<n && s1[i] == s2[p] )
            i++, p++;
        j = n-1, q = m-1;
        while(j>=0 && s1[j] == s2[q])
            j--, q--;
        if(s1[i]=='*' && s1[j]=='*' && p <= q+1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}