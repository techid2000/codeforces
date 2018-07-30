#include <bits/stdc++.h>
using namespace std;

int n,k,minn;
char a;
priority_queue<char,vector<char>,greater<int>> q;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf(" %c",&a);
        q.push(a);
    }
    a = '\0',minn = 0;
    while(!q.empty() && k>0) {
        if(a=='\0' || q.top()-a > 1) {
            minn += q.top()-'a'+1;
            a = q.top();
            k--;
        }
        q.pop();
    }
    if(k == 0) {
        printf("%d\n",minn);
    } else {
        printf("-1\n");
    }
    return 0;
}