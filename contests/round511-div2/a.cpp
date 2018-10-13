#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d",&n);
    int a=1,b=1,c=n-2;
    if(c%3==0) b++, c--;
    printf("%d %d %d\n",a,b,c);
    return 0;
}