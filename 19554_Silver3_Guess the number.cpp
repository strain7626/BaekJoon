#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;cin>>N;
    int l=1,r=N;
    
    while (l<r) {
        int m=(l+r)/2,X;
        cout<<"? "<<m<<endl;
        cin>>X;

        if (X==-1) l=m+1;
        else r=m;
    }
    cout<<"= "<<l;
}