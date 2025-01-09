#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll n, arr[100000];

ll Solve(int start, int end) {
    if (start >= end) return arr[start];

    int mid = (start+end)/2;
    ll width = 1, height = arr[mid];
    ll res = arr[mid];
    int left = mid-1, right = mid+1;

    while (left >= start && right <= end) {
        if (arr[left] > arr[right]) height = min(height, arr[left--]);
        else height = min(height, arr[right++]);
        res = max(res, ++width*height);
    }
    while (left >= start) {
        height = min(height, arr[left--]);
        res = max(res, ++width*height);    
    }
    while (right <= end) {
        height = min(height, arr[right++]);
        res = max(res, ++width*height);    
    }

    res = max(res,Solve(start, mid-1));
    res = max(res,Solve(mid+1, end));

    return res;
} 

 
int main() {
    while (true) {
        cin >> n;
        if (!n) break;
        
        for (int i = 0; i < n; i++) cin >> arr[i];
 
        cout << Solve(0,n-1) << endl;
    }
}