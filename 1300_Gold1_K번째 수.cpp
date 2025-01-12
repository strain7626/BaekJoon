#include <iostream>
#include <algorithm>

using namespace std;

int N, k;
int result = 1;

int main() {
    cin >> N >> k;
    
    int low = 1, high = k;
    
    while (low <= high) {
        int mid = (low+high)/2;

        int cnt = 0;
        for (int i=1;i<=N;i++) {
            cnt += min((mid-1)/i, N);
        }

        if (cnt < k) {low=mid+1;result=mid;}
        else high=mid-1;
    }
    cout << result;
}