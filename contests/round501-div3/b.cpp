#include <bits/stdc++.h>
using namespace std;
map<char,queue<int>>o;
int n;
int a[55];
char s1[55],s2[55];
vector<int> ans;
int main()
{
    scanf("%d",&n);
    scanf(" %s %s",s1+1,s2+1);
    for(int i=1; i<=n; i++) {
        o[s2[i]].push(i);
    }
    for(int i=1; i<=n; i++) {
        a[i] = o[s1[i]].front();
        o[s1[i]].pop();
        if(o[s1[i]].empty()) o.erase(s1[i]);
    }
    if(!o.empty()) {
        printf("-1\n");
        return 0;
    }
    for(int i=1; i<n; i++) {
        for(int j=n; j>i; j--) {
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                ans.push_back(j-1);
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto x:ans)printf("%d ",x);
    return 0;
}