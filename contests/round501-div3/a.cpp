#include <bits/stdc++.h>
using namespace std;

int n,m,p,q;
int a[105];
vector<int>ans;
int main()
{
    scanf("%d%d",&n,&m);
    while(n--) {
        scanf("%d%d",&p,&q);
        for_each(a+p,a+q+1,[](int&x){x=1;});
    }
    for(int i=1;i<=m;i++) 
        if(!a[i])
            ans.push_back(i);
    printf("%d\n",ans.size());
    for(auto x:ans)printf("%d ",x);
    return 0;
}