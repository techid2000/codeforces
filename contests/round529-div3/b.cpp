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
int n,Max1,Max2,Min1,Min2,Max,Min,MIN;
int a[100005];
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  Min1=Min2=INT_MAX;
  Max1=Max2=INT_MIN;
  foru(i,1,n+1) {
    scanf("%d",a+i);
    if(a[i]>Max1) {
      Max2=Max1;
      Max1=a[i];
    } else if(a[i]>Max2) {
      Max2=a[i];
    }
    if(a[i]<Min1) {
      Min2=Min1;
      Min1=a[i];
    } else if(a[i]<Min2) {
      Min2=a[i];
    }
  }
  MIN = INT_MAX;
  foru(i,1,n+1) {
    Max=Max1,Min=Min1;
    if(a[i]==Max1) Max=Max2;
    if(a[i]==Min1) Min=Min2;
    MIN = min(MIN, Max-Min);
  }
  printf("%d\n",MIN);
  return 0;
}