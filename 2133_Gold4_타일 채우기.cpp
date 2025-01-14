#include <iostream>

using namespace std;

int arr[15];

int main() {
    int N;
    cin >> N;
    if (N%2) cout << 0;
    else {
        N/=2;
        arr[0] = 1;
        arr[1] = 3;
        for (int i = 2; i <= N; i++) {
            arr[i] += arr[i-1]*3;
            for (int j = 0; j < i-1; j++) arr[i] += arr[j]*2;
        }
        cout << arr[N];
    }
}