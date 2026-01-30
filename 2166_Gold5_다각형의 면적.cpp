#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    double x1,x2,x3,y1,y2,y3,ans=0; cin>>x1>>y1>>x2>>y2;
    for (int i=2;i<N;i++) {
        cin >> x3 >> y3;
        ans+=(x1*y2+x2*y3+x3*y1-x1*y3-x3*y2-x2*y1)/2;
        x2=x3,y2=y3;
    }
    printf("%.1f",abs(ans));
}