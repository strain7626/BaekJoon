#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << A+B-C << endl;

    int b = B;
    int t = 1;
    while (b) {b/=10; t*=10;}

    cout << A*t+B-C << endl;
}