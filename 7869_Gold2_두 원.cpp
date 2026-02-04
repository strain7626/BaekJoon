#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout<<fixed;
    cout.precision(3);
    double x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    double d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    if (d>r1+r2) cout<<0.000;
    else if (d<abs(r1-r2)||d==0) cout<<acos(-1)*pow(min(r1,r2),2);
    else {
        double t1=2*acos((pow(r1,2)+pow(d,2)-pow(r2,2))/(2*r1*d));
        double t2=2*acos((pow(r2,2)+pow(d,2)-pow(r1,2))/(2*r2*d));
        cout<<0.5*(pow(r1,2)*(t1-sin(t1))+pow(r2,2)*(t2-sin(t2)));
    }
}