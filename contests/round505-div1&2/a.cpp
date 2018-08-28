#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005];
map<char,int>cn;
int fl;
int main() {
    scanf("%d",&n);
    scanf(" %s",s);
    if(n==1){
        printf("Yes\n");
        return 0;
    }
    for(int i=0;i<n;i++) {
        cn[s[i]]++;
        if(cn[s[i]]>1) {
            fl = 1;
            break;
        }
    }
    if(fl) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}