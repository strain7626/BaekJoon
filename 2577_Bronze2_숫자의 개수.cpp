#include <iostream>
#define endl "\n"
using namespace std;

int cnt[10];

int main() {
    int A, B, C; cin >> A >> B >> C;
    int R = A*B*C;

    while (R > 0) {
        cnt[R%10]++;
        R /= 10;
    }
    for (int i : cnt) cout << i << endl;
}