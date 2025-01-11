#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string A;
        cin >> A;
        
        int score = 0, ds = 0;
        for (char a : A) {
            if (a == 'O') ds++;
            else ds = 0;
            score += ds;
        }
        cout << score << endl;
    }
}