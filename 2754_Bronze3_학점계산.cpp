#include <bits/stdc++.h>
using namespace std;

int main() {
    double score;
    char x; cin >> x;
    score = 'E'-x;
    if (score == -1) {
        cout << "0.0";
        exit(0);
    }

    char y; cin >> y;
    if (y == '-') cout << score - 0.3;
    else if (y == '+') cout << score + 0.3;
    else cout << score << ".0";
}