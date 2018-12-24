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
int n,i,a[2005];
vector<pair<int,PII>>v;
int main() {
  //Code here
  scanf("%d",&n);
  for(i=1;i<=n;i++) {
    scanf("%d",&a[i]);
    a[i]+=500000;
  }
  v.push_back(make_pair(1,make_pair(n,500000)));
  for(i=1;i<=n;i++) {
    v.push_back(make_pair(2,make_pair(i,a[i]-i)));
  }
  printf("%d\n",v.size());
  for(i=0;i<v.size();i++) {
    printf("%d %d %d\n",v[i].X,v[i].Y.X,v[i].Y.Y);
  }
  return 0;
}