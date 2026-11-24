#include <bits/stdc++.h>

using namespace std;

int dx,dy,n,q,grd[2020][2020]={};
 
void solve() {
    cin>>dx>>dy>>n>>q;

    if(!dx&&!dy&&!n&&!q) exit(0);
    static int T=1; cout<<"Case "<<T++<<":\n";

    for(int r=1;r<=dx+dy;r++) for(int c=1;c<=dx+dy;c++) grd[r][c]=0;

    for(int i=n;i--;) {
        int x,y; cin>>x>>y;
        grd[x+y][dy+x-y]=1;
    }

    for(int r=1;r<=dx+dy;r++) for(int c=1;c<=dx+dy;c++)
        grd[r][c]+=grd[r-1][c]+grd[r][c-1]-grd[r-1][c-1];

    while(q--) {
        int m,ans=-1,ax,ay; cin>>m;
        for(int y=1;y<=dy;y++) for(int x=1;x<=dx;x++) {
            int tmp=grd[min(dx+dy,x+y+m)][min(dx+dy,dy+x-y+m)]
            -grd[max(0,x+y-m-1)][min(dx+dy,dy+x-y+m)]
            -grd[min(dx+dy,x+y+m)][max(0,dy+x-y-m-1)]
            +grd[max(0,x+y-m-1)][max(0,dy+x-y-m-1)];

            if(tmp>ans) ans=tmp,ax=x,ay=y;
        }
        cout<<ans<<" ("<<ax<<','<<ay<<")\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while(1) solve();
}