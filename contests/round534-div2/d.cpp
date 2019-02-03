#include <bits/stdc++.h>
using namespace std;

long long len,x,y,d,ans;
char s[10005];

int main() {
  while(true) {
    scanf(" %s",s);
    if(s[0]=='e' || s[0]=='m') {
      return 0;
    }
    x=d=1ll,ans=-1ll;
    y=x+1;
    while(true) {
      while(true) {
        printf("? %lld %lld\n",x,y);
        fflush(stdout);
        scanf(" %s",s);
        if(s[0]=='e') return 0;
        if(s[0]=='y') {
          x=y;
          y=x+d;
          d<<=1;
        } else if(y-x<=1) {
          ans=y;
          break;
        } else {
          break;
        }
      }
      if(ans!=-1) break;
      y=x+1,d=1;
    }
    if(ans==2) {
      printf("? %lld %lld\n",2,3);
      fflush(stdout);
      scanf(" %s",s);
      if(s[0]=='x') {
        ans = 1;
      }
    }
    printf("! %lld\n",ans);
    fflush(stdout);
  }
  return 0;
}