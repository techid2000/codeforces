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

const int N = 200005;
vector <int> t[N];
LL so[N];
LL no[N];
LL se[N];
LL ne[N];
LL aso, ase, ano;
int n,u,v;

void dfs(int u,int p) {
    if(t[u].size()==1 && t[u][0]==p) {
        ne[u] = 1;
        return;
    }
    int v;
    LL smne = 0;
    LL smse = 0;
    LL smno = 0;
    LL smso = 0;
    // int sigma_numEvenCube = 0;
    rep(i, t[u].size()) {
        v = t[u][i];
        if(t[u][i]!=p) {
            dfs(v, u);
            //DP
            se[u] += so[v]+no[v];
            ne[u] += no[v];
            so[u] += se[v]+ne[v];
            no[u] += ne[v];
            //Combi
            smne += ne[v];
            smse += se[v];
            smno += no[v];
            smso += so[v];
        }
    }
    ase += se[u];
    //----------//
    aso += so[u];
    ano += no[u];
    rep(i, t[u].size()) {
        if(t[u][i]!=p) {
            v = t[u][i];
            smne -= ne[v];
            smse -= se[v];
            smno -= no[v];
            smso -= so[v];
            ase += se[v]*smne + ne[v]*smse + 2*(smne*ne[v]);
            ase += so[v]*smno + no[v]*smso + 2*(smno*no[v]);
            //----------//
            aso += se[v]*smno + ne[v]*smso + 2*(smno*ne[v]);
            aso += so[v]*smne + no[v]*smse + 2*(smne*no[v]);
            ano += smno * ne[v] + smne * no[v];
        }
    }
    ne[u] += 1;
    return;
}

int main() {
    //Code here
    scanf("%d",&n);
    rep(i, n-1) {
        scanf("%d%d",&u,&v);
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n",ase/2 + (aso-ano)/2 + ano);
    return 0;
}