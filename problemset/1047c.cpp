//Author: techid2000
#include <bits/stdc++.h>
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
  cin.rdbuf(fin.rdbuf());cout.rdbuf(fout.rdbuf());cerr.rdbuf(ferr.rdbuf());
#endif
}
const int N = 300005;
const int Max = 15000005;
int n,a[N],Gcd,cnt[Max],cou,MAx,soe[Max];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code herea
  cin >> n;
  rep(i,n) {
    cin >> a[i];
    if(i==0) Gcd=a[i];
    else Gcd=gcd(Gcd,a[i]);
  }
  rep(i,n) {
    cnt[a[i]/Gcd]++;
  }
  for(int i=2; i<Max; i++) {
    if(!soe[i]) {
      cou = 0;
      for(int j=i; j<Max; j+=i) {
        cou += cnt[j];
        soe[j] = 1;
      }
      amax(MAx,cou);
    }
  }
  watch(MAx);
  if(MAx > 0) cout << n-MAx;
  else cout << -1;
  return 0;
}