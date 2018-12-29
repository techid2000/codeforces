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

const int N = 100005;
char s[]="hard!";
char str[N];
LL dp[N][5];
int a[N];
int len;

LL fn(int i,int j) {
  if(i==len) {
    if(j>=4) {
      return dp[i][4]=1e18;
    } else {
      return dp[i][j]=0;
    }
  }
  if(dp[i][j]!=-1) return dp[i][j];
  if(str[i]==s[j]) {
    return dp[i][j] = min(fn(i+1, j) + a[i], fn(i+1, j+1));
  } else {
    return dp[i][j] = fn(i+1, j);
  }
}

int main() {
  debugMode();
  //Code here
  scanf("%d",&len);
  scanf(" %s",str);
  rep(i, len) {
    scanf("%d",&a[i]);
  }
  memset(dp,-1,sizeof(dp));
  printf("%lld\n",fn(0, 0));
  return 0;
}