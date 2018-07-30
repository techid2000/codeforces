#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,sa,sb;
    sa = sb = 0;
    int a[50],b[50];
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<n; i++) scanf("%d",&b[i]);
    for_each(a,a+n,[&sa](int x){sa+=x;});
    for_each(b,b+n,[&sb](int x){sb+=x;});
    printf(sa>=sb?"Yes\n":"No\n");
    return 0;
}