#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;


int main() {
    cout << 4 + 7 + 8 + 10 + 12 + 18 + 26 + 35 + 42 + 58 + 70 + 100 + 168 + 268;

    int T; cin >> T;
    while (T--) {
        int K; cin >> K;
        int result = 0;

        priority_queue<int> pq;
        while (K--) {
            int x; cin >> x;
            pq.push(-x);
        }

        while (pq.size() > 1) {
            int a = -pq.top(); pq.pop();
            a += -pq.top(); pq.pop();
            result += a;
            pq.push(-a);
        }

        cout << result << endl;
    }
}