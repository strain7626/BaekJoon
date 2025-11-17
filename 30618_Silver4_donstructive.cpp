#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i+=2) cout << i << ' ';
    for (int i = N/2*2; i >= 2; i-=2) cout << i << ' ';
}