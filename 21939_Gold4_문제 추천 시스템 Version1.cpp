#include <bits/stdc++.h>
using namespace std;

int N, M, id;
vector<int> P, L; // id로 접근
map<int,int> P2id;
set<int> vis;

struct cmp1 {
    bool operator()(int a, int b) {
        if (L[a] == L[b]) return P[a] < P[b];
        return L[a] < L[b];
    }
};
struct cmp2 {
    bool operator()(int a, int b) {
        if (L[a] == L[b]) return P[a] > P[b];
        return L[a] > L[b];
    }
};
priority_queue<int,vector<int>,cmp1> PQ1;
priority_queue<int,vector<int>,cmp2> PQ2;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    id = 0;
    for (int i = 0; i < N; i++) {
        int p, l; cin >> p >> l;
        P.push_back(p); L.push_back(l);
        PQ1.push(id);
        PQ2.push(id);
        P2id[p] = id;
        id++;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        string S; cin >> S;
        if (S == "recommend") {
            int t; cin >> t;
            if (t == 1) {
                while (vis.count(PQ1.top())) PQ1.pop();

                cout << P[PQ1.top()] << '\n';
            } else {
                while (vis.count(PQ2.top())) PQ2.pop();

                cout << P[PQ2.top()] << '\n';
            }
        } else if (S == "add") {
            int p, l; cin >> p >> l;
            P.push_back(p); L.push_back(l);
            PQ1.push(id);
            PQ2.push(id);   
            P2id[p] = id;
            id++;
        } else if (S == "solved") {
            int p; cin >> p;
            vis.insert(P2id[p]);
        }
    }
}