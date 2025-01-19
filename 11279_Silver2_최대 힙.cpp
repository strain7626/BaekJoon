#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

int main()
{
    priority_queue<int> heap;
    int N; cin >> N;

    while (N--) {
        int x; cin >> x;
        if (x) heap.push(x);
        else {
            if (heap.empty()) cout << 0 << endl;
            else { 
                cout << heap.top() << endl;
                heap.pop();
            }
        }
    }
}