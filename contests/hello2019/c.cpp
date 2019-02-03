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
int n,op,cl,Min,ans;
map <PII,int> cou;
string str;
stack<char>stk;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  redirect();
  //Code here
  cin >> n;
  rep(_,n) {
    cin >> str;
    for(auto c:str) {
      if(c == '(') stk.push(c);
      else {
        if(!stk.empty() && stk.top()=='(') {
          stk.pop();
        } else {
          stk.push(c);
        }
      }
    }
    op = cl = 0;
    while(!stk.empty()) {
      if(stk.top()=='(') ++op;
      else ++cl;
      stk.pop();
    }
    if(op==0 || cl==0) {
      cou[{op, cl}]++;
    }
  }
  for(auto & [x, y] : cou) {
    if(x.X == x.Y) {
      ans += y/2;
      cou[{x.X, x.Y}] -= y;
    } else {
      Min = min(y,cou[{x.Y, x.X}]);
      cou[{x.X, x.Y}] -= Min; 
      cou[{x.Y, x.X}] -= Min;
      ans += Min; 
    }
  }
  cout << ans;
  return 0;
}