#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

struct cmp {
    bool operator() (int low, int top) {
        if (abs(top) == abs(low)) return top < low;
        return abs(top) < abs(low);
    }
};

int main() {
    cin.tie(0);
    int N; cin >> N;
    priority_queue<int, vector<int>, cmp> pq;

    while (N--) {
        int x; cin >> x;
        
        if (x) pq.push(x);
        else {
            if (pq.empty()) cout << 0 << endl;
            else { cout << pq.top() << endl; pq.pop(); }
        }
    }


}