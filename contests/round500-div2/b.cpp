#include <bits/stdc++.h>
using namespace std;

int n,x;
int a[100005];
int cnt1[200000];
int cnt2[200000];

int main()
{
    scanf("%d%d",&n,&x);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        cnt1[a[i]]++;
        if(cnt1[a[i]] > 1) {
            printf("0\n");
            return 0;
        }
    }
    for(int i=0; i<n; i++) {
        if(a[i] != (a[i]&x)) {
            if(cnt1[a[i]&x] > 0) {
                printf("1\n");
                return 0;
            }
        }
        cnt2[a[i]&x]++;
    }
    for(int i=0; i<200000; i++) {
        if(cnt2[i] > 1) {
            printf("2\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}