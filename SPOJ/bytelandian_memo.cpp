#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<long long , long long> dp;

long long max(long long a, long long b) {
	return a > b ? a : b;	
}

long long count(long long n) {
	if (n == 0)
		return 0;
	if (dp[n] == 0)
		dp[n] = max ((count(n/2) + count(n/3) + count(n/4)), n);
	
	return dp[n];
}

int main() {
	
	// your code here
	long long n;
	long long sum;
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	dp[0] = 0;
	dp[1] = 1;
	
	while(cin>>n) {
		sum = count(n);
		cout<<sum<<'\n';
	}

	return 0;
}