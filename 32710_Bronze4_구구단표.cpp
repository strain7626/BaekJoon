#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> S;
    for (int i = 1; i <= 9; i++) for (int j = 1; j <= 9; j++)
        S.insert(i*j);

    int N; cin >> N;
    cout << S.count(N);
}