//Author: techid2000
#include <bits/stdc++.h>
#pragma region Preparation
#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,a) for(int i=0;i<a;i++)
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
using namespace std;
using PII = pair<int,int>;
using LL = long long;
template<class T,class U>inline bool amin(T& x, U y){return x>y?(x=y,true):false;}
template<class T,class U>inline bool amax(T& x, U y){return x<y?(x=y,true):false;}
ifstream fin("iofiles/in.txt");
ofstream fout("iofiles/out.txt"),ferr("iofiles/err.txt");
inline void redirect() {
#ifndef ONLINE_JUDGE
  cin.rdbuf(fin.rdbuf()); cout.rdbuf(fout.rdbuf());cerr.rdbuf(ferr.rdbuf());
#endif
}
inline void fastio() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
#pragma endregion
struct Edge {
  int u,v,c;
};

const int N = 100005;
vector<int>g[N],ans;
vector<Edge>ve;
int n,m,u,v,c,cmax,lo,hi,mid,use,have;
int ch[N],ord[N],idx;

void dfs(int x) {
  ch[x]=1;
  for(auto y:g[x]) {
    if(ch[y]==0) {
      if(!have)
        dfs(y);
    } else if(ch[y]==1) {
      have = true;
      return;
    }
  }
  ch[x]=2;
}

bool checkCycle() {
  foru(i,1,n)ch[i]=0;
  have = false;
  foru(i,1,n) {
    if(!ch[i])
      dfs(i);
    if(have) return true;
  }
  return false;
}

void topo(int x) {
  ch[x]=-1;
  for(auto y:g[x]) {
    if(ch[y]!=-1) {
      topo(y);
    }
  }
  ord[x]=++idx;
}

int main() {
  fastio();
  redirect();
  //Code here
  cin>>n>>m;
  rep(i,m) {
    cin>>u>>v>>c;
    ve.push_back({u,v,c});
    amax(cmax,c);
  }
  lo=0,hi=cmax;
  while(lo<=hi) {
    mid=(lo+hi)>>1;
    foru(i,1,n) g[i].clear();
    for(auto [x,y,z]:ve) {
      if(z > mid) {
        g[x].push_back(y);
      }
    }
    if(checkCycle()) lo=mid+1;
    else use=mid,hi=mid-1;
  }
  cerr << use;
  foru(i,1,n) g[i].clear();
  for(auto [x,y,z]:ve) {
    if(z > use) {
      g[x].push_back(y);
    }
  }
  idx=1;
  foru(i,1,n) if(ch[i]!=-1) topo(i);
  idx=1;
  for(auto [x,y,z]:ve) {
    if(ord[y]>ord[x])
      ans.push_back(idx);
    idx++;
  }
  cout << use << " " << ans.size() << "\n";
  for(auto x : ans) cout << x << " ";
  return 0;
}