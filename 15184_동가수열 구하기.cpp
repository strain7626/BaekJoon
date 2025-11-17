#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N/2; i++) cout << i+N/2 << ' ' << i << ' ';
    if (N%2) cout << N;
}