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
inline void fastio() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
inline void redirect() {
#ifndef ONLINE_JUDGE
  cin.rdbuf(fin.rdbuf()); cout.rdbuf(fout.rdbuf());cerr.rdbuf(ferr.rdbuf());
#endif
}
#pragma endregion
struct A {
  int i,j,p;
  bool operator <(const A &o)const {
    return p<o.p;
  }
};
struct B {
  int i,j,cnt;
};

int n,m,p,spd[15],ni,nj,np,ncnt,mi,mj,ans[15];
int di[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char c;
int tbl[1005][1005];
queue<A>q;
queue<B>sq;

int valid(int i,int j) {
  if(i>=1&&i<=n&&j>=1&&j<=m&&tbl[i][j]==0) return 1;
  return 0;
}

vector<A>vp;

int main() {
  fastio();
  redirect();
  //Code here
  cin>>n>>m>>p;
  foru(i,1,p) cin>>spd[i];
  foru(i,1,n) {
    foru(j,1,m) {
      cin>>c;
      if(c=='#') tbl[i][j]=-1;
      if(c>='1'&&c<='9') {
        tbl[i][j]=c-'0';
        vp.push_back({i,j,tbl[i][j]});
        ans[tbl[i][j]]++;      
      }
    }
  }
  sort(begin(vp),end(vp));
  for(auto x : vp) {
    q.push(x);
  }
  while(!q.empty()) {
    ni=q.front().i;
    nj=q.front().j;
    np=q.front().p;
    q.pop();
    sq.push({ni,nj,spd[np]});
    while(!sq.empty()) {
      ni=sq.front().i;
      nj=sq.front().j;
      ncnt=sq.front().cnt;
      sq.pop();
      if(ncnt==0) {
        q.push({ni,nj,np});
        continue;
      }
      rep(k, 4) {
        mi=ni+di[k][0];
        mj=nj+di[k][1];
        if(valid(mi,mj)) {
          tbl[mi][mj]=np;
          ans[np]++;
          sq.push({mi,mj,ncnt-1});
        }
      }
    }
  }
  foru(i,1,p) {
    cout << ans[i] << " ";
  }
  return 0;
}