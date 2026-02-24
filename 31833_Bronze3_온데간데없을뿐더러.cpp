#include <bits/stdc++.h>

using namespace std;

string A,B,a,b;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;cin>>N;
    for(int i=0;i<N;i++) {cin>>a;A+=a;}
    for(int i=0;i<N;i++) {cin>>b;B+=b;}
    cout<<(A.size()==B.size()?min(A,B):A.size()<B.size()?A:B);
}