#include <iostream>
#include <queue>
#include <map>
#include <functional>
#define endl "\n"
using namespace std;

class dual_queue {
public :
    int size = 0;
    priority_queue<int> topQ;
    map<int,int> topExcept;
    priority_queue<int, vector<int>, greater<int>> lowQ;
    map<int,int> lowExcept;

    void push(int x) {
        size++;
        topQ.push(x);
        lowQ.push(x);
    }
    int top() {
        if (size == 0) return 0;
        size--;
        while (topExcept[topQ.top()]) {
            topExcept[topQ.top()]--;
            topQ.pop();
        }
        int x = topQ.top(); topQ.pop();
        lowExcept[x]++;
        return x;
    }
    int low() {
        if (size == 0) return 0;
        size--;
        while (lowExcept[lowQ.top()]) {
            lowExcept[lowQ.top()]--;
            lowQ.pop();
        }
        int x = lowQ.top(); lowQ.pop();
        topExcept[x]++;
        return x;    
    }
    void result() {
        if (size) {
            while (lowExcept[lowQ.top()]) {
                lowExcept[lowQ.top()]--;
                lowQ.pop();
            }
            while (topExcept[topQ.top()]) {
                topExcept[topQ.top()]--;
                topQ.pop();
            }
            cout << topQ.top() << " " << lowQ.top() << endl;
        }
        else cout << "EMPTY" << endl;
    }
private :
};

int main() {
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        dual_queue dq;
        int k; cin >> k;
        while (k--) {
            char c; cin >> c;
            int x; cin >> x;
            if (c == 'I') {
                dq.push(x);
            }
            else if (x == -1) dq.low();
            else if (x == 1) dq.top();
        }
        dq.result();
    }
}