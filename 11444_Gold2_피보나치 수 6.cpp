#include <iostream>
#include <map>
#define DIV 1000000007LL;

using namespace std;
typedef long long ll;

ll n;
map<ll, int> f;

int Fibo(ll num) {
    if (num == 0) return 0;
    else if (num == 1) return 1;
    else if (num == 2) return 1;
    else if (f[num]) return f[num];
    else if (num%2) {
        ll t1 = Fibo(num/2);
        ll t2 = Fibo(num/2+1);
        int r = (t1*t1+t2*t2)%DIV;
        f[num] = r;
        return r;
    }
    else {
        ll t1 = Fibo(num/2);
        ll t2 = Fibo(num/2+1);
        ll t3 = Fibo(num/2-1);
        int r = (t1*(t2+t3))%DIV;
        f[num] = r;
        return r;
    }
}

int main() {
    cin >> n;
    cout << Fibo(n);
}