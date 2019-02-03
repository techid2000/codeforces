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
template<class T>ostream& operator<<(ostream& os,const vector<T>&v) {
  os<<"["; for(auto&x:v){os<<x;if(&x!=&v.back())os<<", ";} os<<"]"; return os; }
template<class T>ostream& operator<<(ostream& os,const set<T>&s){
  os<<"{"; for(auto&x:s){if(&x!=&(*begin(s)))os<<", ";os<<x;}os<<"}";return os; }
template<class T,class U>ostream& operator<<(ostream& os,const pair<T,U>&p) {
  os<<"("<<p.X<<", "<<p.Y<<")"; return os; }
template<class T,class U>ostream& operator<<(ostream& os,const map<T,U>&m) {
  os<<"{";for(auto&p:m){if(&p!=&(*begin(m)))os<<", ";os<<p.X<<": "<<p.Y;} os<<"}";return os; }
ifstream fin("iofiles/in.txt");
ofstream fout("iofiles/out.txt"),ferr("iofiles/err.txt");
inline void fastio() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
inline void redirect() {
#ifndef ONLINE_JUDGE
  cin.rdbuf(fin.rdbuf()); cout.rdbuf(fout.rdbuf());cerr.rdbuf(ferr.rdbuf());
#endif
}
#pragma endregion
int n,m,nst,t,opt;
map<string,int>stn;
string s;
PII arp[100005];
int dp[100005][45];
int main() {
  fastio();
  redirect();
  //Code here
  cin>>n>>m;
  foru(i,1,n) {
    cin>>t;
    if(t==1) {
      arp[i] = {1,0};
    } else {
      cin>>s;
      if(stn[s] == 0) 
        stn[s] = ++nst;
      arp[i] = {2,stn[s]};
    }
  }
  fill_n(&dp[0][0],100005*45,-1e9);
  foru(i,1,m) {
    dp[1][i] = 0;
  }
  foru(i,2,n) {
    if(arp[i].X==2) {
      foru(j,1,m) {
        dp[i][j] = dp[i-1][j]+(arp[i].Y==j?1:0);
      }
    } else if(arp[i].X==1) {
      foru(j,1,m) {
        foru(k,1,m) {
          amax(dp[i][j],dp[i-1][k]);
        }
      }
    }
    if(i==n) foru(j,1,nst) amax(opt,dp[n][j]);
  }
  cout<<opt;
  return 0;
}