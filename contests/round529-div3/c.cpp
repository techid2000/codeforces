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

int n,k,c;
priority_queue<int>q;


int main() {
  debugMode();
  //Code here
  scanf("%d%d",&n,&k);
  while(n>0) {
    if(n%2 == 1) {
      q.push(c);
    }
    n/=2,c++;
  }
  if(q.size()>k) {
    printf("NO\n");
    return 0;
  }
  while(q.size()<k) {
    c=q.top();
    q.pop();
    if(c==0) {
      printf("NO\n");
      return 0;
    }
    q.push(c-1);
    q.push(c-1);
  }
  printf("YES\n");
  while(!q.empty()) {
    printf("%d ",(1<<q.top()));
    q.pop();
  }
  return 0;
  return 0;
}