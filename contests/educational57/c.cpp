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

int T;
int ang,ch;
int main() {
  debugMode();
  //Code here
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&ang);
    ch=0;
    foru(n,3,361) {
      foru(m,1,n-1) {
        if((m*180)%n==0 && (m*180)/n==ang) {
          printf("%d\n",n);
          ch=1;
          break;
        }
      }
      if(ch)break;
    }
    if(!ch) printf("-1\n");
  }
  return 0;
}