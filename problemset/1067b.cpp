//Author: techid2000
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a) for(int i=0;i<a;i++)
#define PII pair<int,int>
#define LL long long
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
using namespace std;
int n,k,u,v,rem,yay;
int deg[100005];
int kill[100005];
int die[100005];
vector <int> g[100005];
queue <int> q;
int main() {
    //Code here
    scanf("%d%d",&n,&k);
    rem = n;
    rep(i,n-1) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    foru(i,1,n+1) {
        if(deg[i]==1) {
            q.push(i);
            // printf("first %d\n",i);
        }
    }
    while(q.size() > 1) {
        set <int> s;
        if((--k) < 0) {
            printf("No\n");
            return 0;
        }
        while(!q.empty()) {
            u = q.front();
            q.pop();
            rem--;
            die[u]=1;
            foru(i,0,g[u].size()) {
                v = g[u][i];
                if(!die[v]) {
                    // printf("%d kill %d\n",v,u);
                    deg[v]--;
                    kill[v]++;
                    s.insert(v);
                }
            }
        }
        if(s.size()==2 && rem == 2) {
            printf("No\n");
            return 0;
        }
        for(auto x:s) {
            // printf("prep %d\n",x);
            if(deg[x]>1 || kill[x]<3) {
                printf("No\n");
                return 0;
            }
            if(deg[x]==0) {
                yay=1;
            }
            q.push(x);
        }
        if(yay)break;
    }
    if(rem==1 && q.size()==1 && k==0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}