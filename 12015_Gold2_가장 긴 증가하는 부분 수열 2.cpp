#include <iostream>
#include <vector>

using namespace std;

int N, arr[1000000];
vector<int> LIS;

int FindIdx(int num) {
    int low = 0, high = LIS.size()-1, mid;
    while (low < high) {
        mid = (low+high)/2;
        if (LIS[mid] < num) {low = mid+1;}
        else {high = mid;}
    }
    return high;
}

int Solve() {
    LIS.push_back(arr[0]);
    for(int i=1;i<N;i++) {
        if (LIS.back() < arr[i]) LIS.push_back(arr[i]);
        else LIS[FindIdx(arr[i])] = arr[i];
    }
    return LIS.size();
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    cout << Solve();
}