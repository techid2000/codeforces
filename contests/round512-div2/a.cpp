#include <bits/stdc++.h>
using namespace std;

int n,m;

int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("9%d",&m);
        if(m==1){
            printf("hard\n");
            return 0;
        }
    }
    printf("easy\n");
    return 0;
}