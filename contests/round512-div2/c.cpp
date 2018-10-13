#include <bits/stdc++.h>
using namespace std;
int n,sum,k,ch;
char c;
int s[105],az;
int main() {
    scanf("%d",&n);
    az=1;
    for(int i=0;i<n;i++){
        scanf(" %c",&c);
        s[i]=c-'0';
        sum+=s[i];
        if(s[i]>0)az=0;
    }
    if(az){printf("YES\n");return 0;}
    for(int i=0;i<=sum;i++) {
        k=0;
        ch=1;
        for(int j=0;j<n;j++) {
            if(k+s[j]>i){
                ch=0;
                break;
            } else if(k+s[j]==i){
                while(j+1<n && s[j+1]==0)j++;
                if(j==n-1) k=-1;
                else k=0, ch=-1;
            } else {
                k+=s[j];
            }
        }
        if(!ch)continue;
        if(k==-1 && ch==-1) {
            printf("YES");
            return 0;
        }
    }
    printf("NO\n");
    return 0;    
}