#include <iostream>

using namespace std;
typedef long long ll;

ll A, B, C;

ll solution() {
    ll result = 1;
    while (B) {
        if (B%2) result=result*A%C;
        A=A*A%C;
        B/=2;
    }
    return result;
}

int main() {
    cin >> A >> B >> C;
    cout << solution()%C;
}