#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int cnt = 0;
    for (char c : S) if (c == 'O') cnt++;
    cout << ((cnt >= (N+1)/2) ? "Yes" : "No");
}
