#include <bits/stdc++.h>
using namespace std;

int n,m,i;
char str[1005];

int main() {
    scanf("%d",&n);
    scanf(" %s",str+1);
    for(i=1;i<n;i++) {
        if(str[i]!=str[i+1]) {
            printf("YES\n");
            printf("%c%c",str[i],str[i+1]);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}