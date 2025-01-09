#include <iostream>
#include <cmath>

using namespace std;

long long x,y;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> x >> y;
        long long D = y-x;
        long long cnt = (long long)sqrt(D-1)+1;
        cout << cnt;
        if (D > cnt*(cnt-1) && D <= cnt*cnt) cout << cnt*2-1 << endl;
        else cout << cnt*2-2 << endl;
    }
    return 0;   
}