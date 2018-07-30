#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int b[1005];
double m;
double k = 1;
int main()
{
    scanf("%d",&n);
    scanf("%lf",&m);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        k *= (1-1.0/a[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d",&b[i]);
        k *= (1-1.0/b[i]);
    }
    if(k == 0) printf("-1\n");
    else printf("%.10f\n",m/k - m);
    return 0;
}