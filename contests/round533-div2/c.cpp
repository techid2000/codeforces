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
const LL Mod = 1e9 + 7;
LL n,l,r;
LL rem[3],frem[3],erem[3];
LL mic[200005][3];
int main() {
  fastio();
  redirect();
  //Code here
  cin>>n>>l>>r;
  if(r-l+1==1) {
    rem[l%3]=1;
  } else if(r-l+1==2) {
    rem[l%3]=1;
    rem[r%3]=1;
  } else {
    frem[l%3]=l;
    frem[(l+1)%3]=l+1;
    frem[(l+2)%3]=l+2;
    erem[r%3]=r;
    erem[(r-1)%3]=r-1;
    erem[(r-2)%3]=r-2;
    rem[0] = (erem[0]-frem[0])/3+1;
    rem[1] = (erem[1]-frem[1])/3+1;
    rem[2] = (erem[2]-frem[2])/3+1;
  }
  mic[1][0] = rem[0];
  mic[1][1] = rem[1];
  mic[1][2] = rem[2];
  foru(i, 2, n) {
    mic[i][0] = (mic[i-1][0]*rem[0])+(mic[i-1][1]*rem[2])+(mic[i-1][2]*rem[1]);
    mic[i][1] = (mic[i-1][0]*rem[1])+(mic[i-1][1]*rem[0])+(mic[i-1][2]*rem[2]);
    mic[i][2] = (mic[i-1][0]*rem[2])+(mic[i-1][1]*rem[1])+(mic[i-1][2]*rem[0]);
    mic[i][0] %= Mod;
    mic[i][1] %= Mod;
    mic[i][2] %= Mod;
  }
  cout << mic[n][0];
  return 0;
}