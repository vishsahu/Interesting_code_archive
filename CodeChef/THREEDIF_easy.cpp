#include<iostream>
using namespace std;

main() {
	long long unsigned int n[3] = {0};
	long long unsigned int p;
	long long unsigned int mod = (long long unsigned int)(10e9) + 7;
	int T, min, max, middle;
	cin >> T;
	while (T-- > 0) {
		cin >> n[0] >> n[1] >> n[2];
		min = n[0] > n[1] ? (n[1] > n[2] ? 2 : 1) : (n[0] > n[2] ? 2 : 0);
		max = n[0] > n[1] ? (n[0] > n[2] ? 0 : 2) : (n[1] > n[2] ? 1 : 2);
		middle = 3 - min - max;
		p = n[min] % mod;
		n[middle] = (n[middle] - 1) % mod;
		p = p * n[middle];
		p = p % mod;
		n[max] = (n[max] - 2) % mod;
		p = p * n[max];
		p = p % mod;
		cout << p << endl;
	}
}
