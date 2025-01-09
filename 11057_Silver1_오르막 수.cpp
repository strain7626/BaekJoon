#include <iostream>

using namespace std;

long long endNum[10] = {1,1,1,1,1,1,1,1,1,1};
int N;

int main() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        for (int idx = 1; idx < 10; idx++) {
            endNum[idx] += endNum[idx-1]%10007;
        }
    }
    long long sum = 0;
    for (int i = 0; i < 10; i++) sum += endNum[i];
    cout << sum%10007;

    return 0;
}