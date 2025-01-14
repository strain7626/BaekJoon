#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A[1000000], D[1000000];

void Div(int low, int high);

void Front(int low, int high) {
    if (low == high) {D[low] = 1;return;}
    Div(low, high);
    int mid = (low+high)/2;
    for (int i = mid+1; i <= high; i++) {
        int M = 0;
        for (int j = low; j <= low+1; j++) {
            if (A[i] > A[j] && M < D[j]) M = D[j];
        }
        D[i] += M;
    }
}

void Back(int low, int high) {
    if (low == high) {D[low] = 1;return;}
    Div(low, high);
    int mid = (low+high)/2;
    for (int i = low; i <= mid; i++) {
        int M = 0;
        for (int j = mid+1; j <= high; j++) {
            if (A[i] < A[j] && M < D[j]) M = D[j];
        }
        D[i] += M;
    }
}

void Div(int low, int high) {
    int mid = (low+high)/2;
    Front(low,mid);Back(mid+1,high);
}

int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];
    Front(0,N-1);
    int M = 0;
    for (int i=0;i<N;i++) if (M < D[i]) M = D[i];
    cout << M;
    
}