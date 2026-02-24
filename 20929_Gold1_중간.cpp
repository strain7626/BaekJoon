#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,l1,l2,m1,m2,r1,r2,a,b;cin>>N;
    l1=l2=1,r1=r2=N;
    do {
        m1=(l1+r1)/2,m2=(l2+r2)/2;
        cout<<"? A "<<m1<<endl;
        cin>>a;
        cout<<"? B "<<m2<<endl;
        cin>>b;

        if (a<b) l1=m1+1,r2=m2;
        else l2=m2+1,r1=m1;
    } while (l1<=r1&&l2<=r2);
    cout<<"! "<<min(a,b);
}