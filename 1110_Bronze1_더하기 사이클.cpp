#include <iostream>

using namespace std;

int main(){
    int cur, nxt, cnt = 0;
    cin >> cur;
    nxt = cur;
    while (true) {
        nxt = 10*(nxt%10) + (nxt/10+nxt%10)%10;
        cnt += 1;
        if (nxt == cur) break;
    }
    cout << cnt;
    return 0;
}