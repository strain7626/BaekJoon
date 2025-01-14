#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    while (1) {
        cin>>a>>b>>c;
        if (a>c) {swap(a,c);}
        if (b>c) {swap(b,c);}
        if (!(a||b||c)) break;
        if (a*a+b*b==c*c) cout << "right\n";
        else cout << "wrong\n";
    }
}