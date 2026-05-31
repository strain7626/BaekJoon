#include <bits/stdc++.h>

using namespace std;

double b,c,a1,a2;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>b>>c>>a1>>a2;
    a2/=a1;
    a1=0;
    while(1) {
        a1=a2;
        a2=b+(c/a2);
        if(abs(a1-a2)<0.0000001) break;
    }
    cout<<fixed<<a2<<'\n';
}