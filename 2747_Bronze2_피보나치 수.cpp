#include <iostream>
#define endl "\n"
using namespace std;

long long F[91] = {0,1};

int main() {
    for (int i = 2; i <= 90; i++) F[i] = F[i-1] + F[i-2];
    int N; cin >> N;
    cout << F[N];
}