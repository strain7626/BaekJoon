#include <iostream>

using namespace std;
typedef long long ll;

int N, A[5][5];
ll B;

int rst_A[5][5];

void Input() {
    cin >> N >> B;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        cin >> A[i][j];
}

void Output(int x[5][5]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
}

void Copy(int x[5][5], int y[5][5]) {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        x[i][j] = y[i][j];
}

void Mult(int x[5][5], int y[5][5]) {
    int t[5][5];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int temp = 0;
        for (int k = 0; k < N; k++)
            temp += x[i][k]*y[k][j];
        t[i][j] = temp%1000;
    }
    Copy(x,t);
}

void Square(int x[5][5]) {
    int _x[5][5];
    Copy(_x,x);
    Mult(x,_x);
}

void Solve() {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    if (i==j)
        rst_A[i][j] = 1;
    
    while (B) {
        if (B%2) {
            Mult(rst_A, A);
        }
        Square(A);
        B/=2;
    }
}

int main() {
    Input();
    Solve();
    Output(rst_A);
}