#include <iostream>

using namespace std;

int K,N;
int arr[10000];
int len = 0;

void Input() {
    cin >> K >> N;
    for (int i = 0; i < K; i++) 
    cin >> arr[i];
}

int Solve(int div) {
    int R = 0;
    for (int i = 0; i < K; i++) 
        R += arr[i]/div;
    return R;
}

int main() {
    Input();
    
    int div = 1;
    for (int _=0;_<30;_++) div*=2;

    while (div) {
        if (Solve(len+div)>=N) len+=div;
        div/=2;
    }
    
    cout << len;

    return 0;
}