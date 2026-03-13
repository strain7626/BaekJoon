#include <bits/stdc++.h>

using namespace std;

int brd[9][9];

bool check(int y,int x,int n) {
    int py=y/3*3,px=x/3*3;
    for(int i=0;i<9;i++) {
        if(brd[i][x]==n) return 0;
        if(brd[y][i]==n) return 0;
        if(brd[py+(i/3)][px+(i%3)]==n) return 0;
    }
    return 1;
}

void solve(int y,int x) {
    if(y==9) {
        for(int i=0;i<9;i++,cout<<'\n') for(int j=0;j<9;j++) cout<<brd[i][j]; 
        exit(0);
    }

    if(!brd[y][x]) {
        for(int n=1;n<=9;n++) if(check(y,x,n)) {
            brd[y][x]=n;
            solve(y+(x+1)/9,(x+1)%9);
            brd[y][x]=0;
        }
    } else solve(y+(x+1)/9,(x+1)%9);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for(int y=0;y<9;y++) for(int x=0;x<9;x++) {
        char c;cin>>c;
        brd[y][x]=c-'0';
    }

    solve(0,0);
}