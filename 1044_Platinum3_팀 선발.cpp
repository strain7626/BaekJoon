#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int N;
long long base;
vector<long long> S;
set<long long> S1, S2;

int main() {
    cin >> N;
    vector<long long> tmp(N);
    for (int i = 0; i < N; i++) cin >> tmp[i];
    base = 0;
    S = vector<long long>(N);
    for (int i = 0; i < N; i++) {
        long long x; cin >> x;
        S[i] = x+tmp[i]; base -= x;

        if (i%2) S1.insert(x);
        else S2.insert(x);
    }





}