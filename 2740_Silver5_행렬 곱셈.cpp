#include <iostream>

using namespace std;

int N,M,K;
int A[100][100], B[100][100];
int R[100][100];

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        cin >> A[i][j];
    cin >> M >> K;
    for (int i = 0; i < M; i++) for (int j = 0; j < K; j++)
        cin >> B[i][j];
}

int main() {
    Input();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int t = 0;
            for (int k = 0; k < M; k++)
                t += A[i][k]*B[k][j];
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}