#include <bits/stdc++.h>
using namespace std;
int ok;
int n;
int ch[1005];
int adj[1005];
void df(int u) {
    ch[u]=1;
    if(ch[adj[u]]==0 && !ok) {
        df(adj[u]);
    } else if(ch[adj[u]]==1) {
        ok = adj[u];
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&adj[i]);
    for(int i=1;i<=n;i++) {
        memset(ch,0,sizeof(ch));
        ok=0;
        df(i);
        printf("%d ",ok);
    }
}