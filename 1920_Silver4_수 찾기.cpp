#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int arr[100000];

void Binary(int num) {
    int l=0, r=N-1;
    int mid;
    while (l<=r) {
        mid = (l+r)/2;
        if (arr[mid]==num) {printf("1\n");return;}
        else if (arr[mid] > num)
            r = mid-1;
        else
            l = mid+1;
    }
    printf("0\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr+N);
    
    cin >> M;
    int t;
    for (int i = 0; i < M; i++) {
        cin >> t;
        Binary(t);
    }
    return 0;
}