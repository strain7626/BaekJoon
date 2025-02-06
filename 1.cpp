#include <iostream>

using namespace std;

long long N;
long long shirt[7];
long long T, P;
long long Tshirt;

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= 6; i++) cin >> shirt[i];
	cin >> T >> P;
	for(int i = 1; i <= 6; i++){
		if(shirt[i] % T == 0) Tshirt += (shirt[i] / T);
		else Tshirt += (shirt[i] / T + 1);
	}
	cout << Tshirt << "\n";
	cout << N / P << " " << N % P;
	return 0;
}