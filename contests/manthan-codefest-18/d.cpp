#include <bits/stdc++.h>
using namespace std;
int n;
int u,v,k;
int ch[200005];
queue<int>q;
vector <int> g[200005];
vector <int> seq;
int order[200005];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n-1;i++) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&u);
        seq.push_back(u);
        order[u]=i;
    }
    k=1;
    q.push(1);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        ch[u]=1;
        vector<int>v;
        for(int i=0;i<g[u].size();i++) {
            if(!ch[g[u][i]])
            v.push_back(g[u][i]);
        }
        sort(v.begin(),v.end(),[](int x,int y){return order[x]<order[y];});
        for(int i=0;i<v.size();i++) {
            if(seq[k++] != v[i]) {
                printf("No\n");
                return 0;
            }
            q.push(v[i]);
        }
    }
    printf("Yes\n");
    return 0;
}

