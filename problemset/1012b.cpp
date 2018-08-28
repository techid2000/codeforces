#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int>g[2*N];
int n,m,k,x,y,cnt;
int ch[2*N];
queue<int>q;
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++) {
        scanf("%d%d",&x,&y);
        g[x].push_back(y+n);
        g[y+n].push_back(x);
    }
    for(int i=1;i<=n+m;i++) {
        if(!ch[i]) {
            cnt++;
            q.push(i);
            ch[i]=1;
            while(!q.empty()) {
                for(auto adj:g[q.front()]) {
                    if(!ch[adj]){
                        ch[adj]=1;
                        q.push(adj);
                    }
                }
                q.pop();
            }
        }
    }
    printf("%d\n",cnt-1);
    return 0;
}