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

LL n,m,t,d,y,cost,s,a[100005],c[100005];
priority_queue < pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>> > q;
int main() {
  fastio();
  redirect();
  //Code here
  cin>>n>>m;
  foru(i,1,n) cin>>a[i];
  foru(i,1,n) cin>>c[i];
  foru(i,1,n) {
    q.push({c[i],i});
  }
  rep(i,m) {
    cin>>t>>d;
    cost = 0;
    while(d>0) {
      if(a[t]>0) {
        s=min(a[t],d);
        a[t]-=s;
        cost+=s*c[t];
        d-=s;
      } else {
        while(d>0&&!q.empty()) {
          y = q.top().Y;
          if(a[y]==0) {
            q.pop();
            continue;
          }
          s=min(a[y],d);
          a[y]-=s;
          cost+=s*c[y];
          d-=s;
        }
        if(q.empty()&&d>0) {
          cost=0;
          break;
        }
      }
    }
    cout<<cost<<'\n';
  }
  return 0;
}