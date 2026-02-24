#include <bits/stdc++.h>

using namespace std;

int main() {
    int m=1,M=1e9;
    for (int i=0;i<100;i++) {
        int x;cin>>x;
        if (m==x&&x==M) {cout<<'=';break;}
        if (x-m<M-x) m=max(m,x+1),cout<<'>';
        else M=min(M,x-1),cout<<'<';
        cout<<endl;
    }
}