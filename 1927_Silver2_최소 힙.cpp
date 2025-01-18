#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> heap;
    int N;
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        if (x)
            heap.push(-x);
        else {
            if (heap.size()) {
                cout << -heap.top() << endl;
                heap.pop();
            }
            else cout << "0" << endl;
        }   
    }
}