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
int n,sum,Min,usei,smin,a[10005];
int main() {
  fastio();
  redirect();
  //Code here
  cin>>n;
  foru(i,1,n)cin>>a[i];
  smin = 1e9;
  foru(i,1,100) {
    sum = 0;
    foru(j,1,n) {
      Min = abs(i-a[j]);
      if(i-1>0) {
        amin(Min, abs(i-1-a[j]));
      }
      amin(Min, abs(i+1-a[j]));
      sum += Min;
    }
    if(amin(smin,sum)) {
      usei=i;
    }
  }
  cout << usei << " " << smin;
  return 0;
}