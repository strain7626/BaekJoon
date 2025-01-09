#include <iostream>

using namespace std;

int N,M,min6=1001,min1=1001;

void Input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int t1,t2;
        cin >> t1 >> t2;
        if (t1 < min6) min6 = t1;
        if (t2 < min1) min1 = t2;
    }
    if (min1*6 < min6) min6 = min1*6;
}

int main() {
    Input();
    int result = (N/6)*min6;
    if (min6 < min1*(N%6)) result += min6;
    else result += min1*(N%6);
    cout << result;
    return 0;
}