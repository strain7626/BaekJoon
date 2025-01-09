#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;
        cout << 100*(N%H ? N%H : H) + ((N-1)/H+1) << endl;
    }
}