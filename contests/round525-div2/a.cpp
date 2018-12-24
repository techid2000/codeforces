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
int main() {
  //Code here
  int x,a,b;
  scanf("%d",&x);
  for(a=1;a<=x;a++) {
    for(b=1;b<=x;b++) {
      if(a%b==0 && a*b>x && a<x*b){
        printf("%d %d\n",a,b);
        return 0;
      }
    }
  }
  printf("-1\n");
  return 0;
}