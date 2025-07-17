#include <iostream>
#include <string>
using namespace std;

int gear[6], K;

void rotate(int N1, int N2, int D) {
    if (!(N2%5)) return;

    if (N1 > N2) {
        if (!(((gear[N1]>>1)&1)^((gear[N2]>>5)&1))) return;
        rotate(N2, N2-1, -D);
    }
    if (N2 > N1) {
        if (!(((gear[N1]>>5)&1)^((gear[N2]>>1)&1))) return;
        rotate(N2, N2+1, -D);
    }
    if (D == 1) gear[N2] = (gear[N2]>>1) + ((gear[N2]&1)<<7);
    if (D == -1) gear[N2] = ((gear[N2]<<1)&((1<<8)-1)) + (gear[N2]>>7);       
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for (int i = 1; i <= 4; i++) for (int j = 7; j >= 0; j--) {
        char x; cin >> x;
        gear[i] += ((x-'0') << j);
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
       int N, D; cin >> N >> D;
       rotate(N, N-1, -D);
       rotate(N, N+1, -D);
       if (D == 1) gear[N] = (gear[N]>>1) + ((gear[N]&1)<<7);
       if (D == -1) gear[N] = ((gear[N]<<1)&((1<<8)-1)) + (gear[N]>>7);
    }
    
    int ans = 0;
    for (int i = 1; i <= 4; i++) 
        ans += ((gear[i]>>7)<<(i-1));

    cout << ans;
}