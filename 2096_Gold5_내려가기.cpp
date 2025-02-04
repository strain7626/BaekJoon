#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int max(int arr[3]) {
    int M = 0;
    for (int i=0;i<3;i++) M = max(M,arr[i]);
    return M;
}
int min(int arr[3]) {
    int m = 2e9;
    for (int i=0;i<3;i++) m = min(m,arr[i]);
    return m;
}

int main() {
    int N; cin >> N;
    
    int M[3] = {0,0,0}, m[3] = {0,0,0};
    
    for (int i=0;i<N;i++) {
        int A[3]; cin >> A[0] >> A[1] >> A[2];

        int temp[3];

        temp[0] = max(M[0],M[1]) + A[0];
        temp[1] = max(M) + A[1];
        temp[2] = max(M[1],M[2]) + A[2];
        for (int i=0;i<3;i++) M[i] = temp[i];
    
        temp[0] = min(m[0],m[1]) + A[0];
        temp[1] = min(m) + A[1];
        temp[2] = min(m[1],m[2]) + A[2];
        for (int i=0;i<3;i++) m[i] = temp[i];
    }

    cout << max(M) << " " << min(m);
}