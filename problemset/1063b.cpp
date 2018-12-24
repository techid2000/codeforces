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

char a[2005][2005];
int minR[2005][2005];
int pass[2005][2005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n,m,r,c,x,y,cnt;
int cx,cy,cR,ax,ay,nR;
#define node pair<int,PII>
priority_queue < minheap(node) > q;
#undef node

int process() {
    fill_n (&minR[0][0], 2005*2005, 1e9);
    minR[r][c] = 0;
    pass[r][c] = 1;
    q.push(make_pair(0, make_pair(r,c)));
    while(!q.empty()) {
        cx = q.top().Y.X;
        cy = q.top().Y.Y;
        cR = q.top().X;
        q.pop();
        rep(k, 4) {
            ax = cx + dx[k], ay = cy + dy[k];
            if(k == 0) nR = cR + 1;
            else nR = cR;
            if(ax < 1 || ax > n || ay < 1 || ay > m || a[ax][ay]=='*') continue;
            if(nR < minR[ax][ay]) {
                minR[ax][ay] = nR;
                pass[ax][ay] = 1;
                q.push(make_pair(nR, make_pair(ax, ay)));
            }
        }
    }
    foru (i, 1, n+1) {
        foru(j, 1, m+1) {
            if(pass[i][j]) {
                if(minR[i][j]-(j-c) <= x && minR[i][j] <= y) {
                    cnt++;
                }
            }
            // if(a[i][j]=='*') putchar('*');
            // else printf("%d",minR[i][j]-(j-c));
        }
    }
    return cnt;
}

int main() {
    //Code here
    scanf("%d%d",&n,&m);
    scanf("%d%d",&r,&c);
    scanf("%d%d",&x,&y);
    foru (i, 1, n+1) {
        scanf(" %s",a[i] + 1);
    }
    printf("%d\n", process());
    return 0;
}