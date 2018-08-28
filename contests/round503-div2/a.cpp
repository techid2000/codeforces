#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h,a,b;
ll ta,fa,tb,fb;
ll step;
int k;
int main() {
    cin>>n>>h>>a>>b>>k;
    while(k--) {
        cin>>ta>>fa>>tb>>fb;
        step=0;
        if(ta == tb) {
            printf("%lld\n",abs(fa-fb));
        } else {
            if(fa<a||fa>b) {
                if(abs(fa-a) < abs(fa-b)) {
                    step += abs(fa-a);
                    fa = a;
                } else {
                    step += abs(fa-b);
                    fa = b;
                }
            }
            step+=abs(ta-tb);
            step+=abs(fb-fa);
            printf("%lld\n",step);
        }
    }
}