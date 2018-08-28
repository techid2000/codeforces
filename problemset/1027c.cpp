#include <bits/stdc++.h>
using namespace std;
int T;
int n,a,fl,a1,a2;
int cn[10005];
double fr,mn;
vector<int>av;
int main() {
    scanf("%d",&T);
    while(T--) {
        memset(cn,0,sizeof(cn));
        av.clear();
        scanf("%d",&n);
        fl = 0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a);
            cn[a]++;
            if(cn[a]==2)av.push_back(a);
            if(cn[a]==4){
                fl = a;
            }
        }
        if(fl > 0) {
            printf("%d %d %d %d\n",fl,fl,fl,fl);
            continue;
        }
        mn = DBL_MAX;
        sort(av.begin(),av.end());
        for(int i=1; i<av.size(); i++) {
            fr = 1.0*av[i]/av[i-1];
            if(fr < mn) {
                mn = fr;
                a1 = av[i];
                a2 = av[i-1];
            }
        }
        printf("%d %d %d %d\n",a1,a1,a2,a2);
    }
}