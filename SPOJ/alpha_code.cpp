#include <bits/stdc++.h> 

using namespace std;

int dp[5000];

int main() {		

	char arr[5001];
	int n;
	int num;

	while(cin>>arr) {
		if (arr[0] == '0') 
			break;
		n = strlen(arr);

		for (int i = 0; i < n; i++) {
			dp[i] = 0;
		}
		dp[0] = 1;

		for (int i = 1; i < n; i++) {
			num = (arr[i-1] - '0') * 10 + (arr[i] - '0');

			if (num == 10 || num == 20) {
				if (i == 1)
					dp[i] = dp[i-1];
				else 
					dp[i] = dp[i-2];
			}

			else if (num > 9 && num < 27) {
				if (i == 1)
					dp[i] = dp[i-1] + 1;

				else {
					dp[i] = dp[i-1] + dp[i-2];
				}
			} 

			else {
				dp[i] = dp[i-1];
			}
		}
		cout<<dp[n-1]<<'\n'; 
	}
	return 0;
}