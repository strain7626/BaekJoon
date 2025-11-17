#include <iostream>
using namespace std;



int main() {
    int N; cin >> N;

    int X = N/3, Y = X*2;
    if (N%3 == 2) X++,Y++;

    cout << X << '\n';
    for (int i = N; i >= 3; i-=3) cout << i << ' '; if (N%3 == 2) cout << 1; cout << '\n';
        
    cout << Y << '\n';
    for (int i = N; i >= 3; i-=3) cout << i-1 << ' ' << i-2 << ' '; if (N%3 == 2) cout << 2; cout << '\n';
}