//Author: techid2000
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a) for(int i=0;i<a;i++)
#define PII pair<int,int>
#define LL long long
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
using namespace std;
inline void debugMode() {
#ifndef ONLINE_JUDGE
  freopen("iofiles/in.txt","r",stdin);
  freopen("iofiles/out.txt","w",stdout);
#endif
}
int n,len;
string s;
string S[105][2];
int order[105][2];
vector<pair<int,char>>v;
int main() {
  debugMode();
  //Code here
  cin>>n;
  rep(i, 2*n-2) {
    cin>>s;
    len=s.length();
    if(S[len][0]!="") {
      S[len][1]=s;
      order[len][1]=i;
    } else {
      S[len][0]=s;
      order[len][0]=i;
    }
  }
  // foru(i,1,n) {
  //   cout<<S[i][0]<<' '<<S[i][1]<<'\n';
  // }
  if(n>=2){
    if((S[1][1]+S[2][0][1]==S[2][0] && S[2][1][0]+S[1][0]==S[2][1]) ||
        (S[1][1]+S[2][1][1]==S[2][1] && S[2][0][0]+S[1][0]==S[2][0])) {
          swap(S[1][0],S[1][1]);
          swap(order[1][0], order[1][1]);  
        }
  }
  foru(i,2,n) {
    if(S[i-1][0]+S[i][1][i-1]==S[i][1] && S[i][0][0]+S[i-1][1]==S[i][0]) {
      swap(S[i][0], S[i][1]);
      swap(order[i][0],order[i][1]);
    }
  }
  foru(i,1,n) {
    v.push_back(make_pair(order[i][0],'P'));
    v.push_back(make_pair(order[i][1],'S'));
  }
  sort(v.begin(),v.end());
  for(auto P:v) {
    cout<<P.Y;
  }
  return 0;
}