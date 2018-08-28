#include <bits/stdc++.h>
using namespace std;

int n,k;
int op,cl;
char br[200005];
int main() {
    scanf("%d%d",&n,&k);
    scanf(" %s",br);
    op = cl = k/2;
    for(int i=0; i<n; i++) {
        if(br[i]=='(' && op-- > 0) {
            putchar('(');
        } else if(br[i]==')' && cl-- > 0) {
            putchar(')');
        }
    }
    return 0;
}