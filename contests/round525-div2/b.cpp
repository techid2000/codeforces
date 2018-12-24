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
priority_queue<minheap(int)>q;
int main() {
  //Code here
  int n,k,a;
  scanf("%d%d",&n,&k);
  rep(i,n) {
    scanf("%d",&a);
    q.push(a);
  }
  int s=0;
  while(!q.empty() && k>0) {
    while(!q.empty() && q.top()-s<=0) 
      q.pop();
    if(!q.empty()) {
      printf("%d\n", q.top()-s);
      s=q.top();
      q.pop();
      k--;
    }
  }
  while(k>0) {
    printf("0\n");
    k--;
  }
  return 0;
}