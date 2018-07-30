#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int main()
{
    int n,m,k,s;
    vector<int>a(105,0);
    vector<int>b;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) {
        scanf("%d",&k);
        a[k]++;
    }
    for(int i=1; i<=100; i++) {
        if(a[i] > 0) {
            b.push_back(a[i]);
        }
    }
    for(int i=100; i>=1; i--) {
        s = 0;
        for(int j=0; j<b.size(); j++) {
            s += b[j]/i;
        }
        if(s >= n) {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}