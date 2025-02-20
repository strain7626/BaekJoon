#include <iostream>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int x, y; cin >> x >> y;
        int dist = y-x;

        int ans = 0;
        while (dist > 0) {
            ans++;
            dist -= (ans+1)/2;
        }
        cout << ans << endl;
    }
}