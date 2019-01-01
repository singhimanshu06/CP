#include <bits/stdc++.h>

using namespace std;

long long phi(long long n) {
	long long result = n;
	for (long long i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n = n/i;
			}
			result = result - result/i; //subtract all the multiples of prime factor i.
		}
	}
	if (n > 1) {
		result -= result/n; //if n > 1, subtract all the multiles of n.
	}
	return result;
}

int main () {
	int t;
	long long n;

	cin>>t;

	while (t--) {
		cin>>n;
		cout<<phi(n)<<'\n';
	}
	return 0;
}