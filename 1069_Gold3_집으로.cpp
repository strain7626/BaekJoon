#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout<<fixed;
    cout.precision(16);

    double X,Y,D,T;cin>>X>>Y>>D>>T;
    double d=sqrt(X*X+Y*Y);
    int a=d/D;

    double ans[]={
        d,
        T*a+(d-D*a),
        T*(a+1)+(a?0:D-d),
        T*max(2,a+1)
    };

    cout << *min_element(ans,ans+4);
}