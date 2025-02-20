#include <iostream>
#include <queue>
#include <set>
#define endl "\n"
using namespace std;

typedef long long ll;

ll  L;
int N, K;
queue<ll> Q;
set<ll> visit;

void BFS() {
    ll t = Q.size();
    while (t--) {
        ll now = Q.front();
        Q.pop();

        if (Q.size()-t >= K) return;

        if (now-1>=0 && visit.count(now-1) == 0) {
            Q.push(now-1);
            visit.insert(now-1);
        }
        if (now+1<=L && visit.count(now+1) == 0) {
            Q.push(now+1);
            visit.insert(now+1);
        }
    }
}

int main() {
    cin >> L >> N >> K;
    for (int i=0;i<N;i++) {
        ll a; cin >> a;
        Q.push(a);
        visit.insert(a);
    }


    ll num = 0;
    while (K > 0) {
        for (int i = 0; i < (Q.size()<K ? Q.size() : K); i++) cout << num << endl;
        K-=Q.size();

        BFS();
        num++;
    }

}