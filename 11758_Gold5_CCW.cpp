#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    int CCW = (x2-x1)*(y3-y2)-(x3-x2)*(y2-y1);

    cout << (CCW>0)-(CCW<0);
}