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
#pragma endregion
int n,k,a[105],Max,sum,tmp;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin >> n >> k;
  foru(i, 1, n) {
    cin >> a[i];
    sum += a[i];
  }
  foru(b, 1, k) {
    tmp = 0;
    for(int i=b; i<=n; i+=k) {
      tmp += a[i];
    }
    amax(Max, abs(sum-tmp));
  }
  cout << Max << "\n";
  return 0;
}