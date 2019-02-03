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
int y,b,r,Max;
int main() {
  debugMode();
  //Code here
  scanf("%d%d%d",&y,&b,&r);
  foru(i,1,y+1) {
    if(i+1<=b && i+2<=r) {
      Max = max(Max, i+(i+1)+(i+2));
    }
  }
  printf("%d\n",Max);
  return 0;
}