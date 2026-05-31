#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<N;j++) cout<<' ';
        for(int j=N;j>=0;j--) cout<<(j==i?'*':' ');
        for(int j=N;j>=0;j--) cout<<(j==i?'*':' ');
        for(int j=1;j<=N;j++) cout<<(j==i?'*':' ');
        cout<<'\n';
    }
    for(int i=1;i<=N;i++) {
        for(int j=N;j>=0;j--) cout<<(j==i?'*':' ');
        for(int j=0;j<N;j++) cout<<' ';
        for(int j=0;j<=N;j++) cout<<(j+1==i?'*':' ');
        for(int j=N;j>=0;j--) cout<<(j==i?'*':' ');
        cout<<'\n';
    }
}