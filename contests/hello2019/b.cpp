//Author: techid2000
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,a) for(int i=0;i<a;i++)
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
#define watch(x) cout<<#x<<" = "<<x<<'\n'
using namespace std;
using PII = pair<int,int>;
using LL = long long;
template<class T,class U>inline void amin(T& x, U y){x=min(x,y);}
template<class T,class U>inline void amax(T& x, U y){x=max(x,y);}
ifstream fin("iofiles/in.txt");
ofstream fout("iofiles/out.txt");
inline void redirect() {
#ifndef ONLINE_JUDGE
  cin.rdbuf(fin.rdbuf()); cout.rdbuf(fout.rdbuf());
#endif
}

int n,a[20];
bool dfs(int x,int u) {
  if(u == n) {
    if(x == 0) return true;
    else return false;
  }
  return dfs((((x+a[u])%360)+360)%360,u+1)||dfs((((x-a[u])%360)+360)%360,u+1);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin >> n;
  rep(i,n)
    cin >> a[i];
  if(dfs(0,0)) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}