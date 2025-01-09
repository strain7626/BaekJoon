#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, m, max = 0;
    int tree[1000001];
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> tree[i];
    
    sort(tree, tree + n);
    
    ll low = 0;
    ll high = tree[n - 1];
    
    while(low <= high){ 
        ll sum = 0;
        ll mid = (low + high) / 2;
        
        for(int i = 0; i < n; i++)
            if(tree[i] - mid > 0) sum += tree[i] - mid;
        
        if(sum >= m) {
            max = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    
    cout << max; 
    
    return 0;
}