#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, int> id;
int cnt = 0;

pair<int,int> Info[111][111];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string name, t1, t2; int day; cin >> name >> day >> t1 >> t2;
        int h1 = stoi(t1.substr(0,2)), m1 = stoi(t1.substr(3));
        int h2 = stoi(t2.substr(0,2)), m2 = stoi(t2.substr(3));

        if (!id.count(name)) id[name] = {cnt++};
        Info[id[name]][(day-1)/7].first++;
        Info[id[name]][(day-1)/7].second += 60*(h2-h1) + m2-m1;
    }
    
    for (int i = 0; i < M/7; i++) for (pair<string,int> j : id) 
        if (Info[j.second][i].first < 5 || Info[j.second][i].second < 60*60) id.erase(j.first);

    if (!id.size()) cout << -1;
    else for (pair<string,int> j : id)
        cout << j.first << '\n';
}