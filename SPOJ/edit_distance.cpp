#include <bits/stdc++.h>

using namespace std;

int dp[2001][2001];
string a, b;

int min(int a, int b, int c) {
	return min(a, min(b, c));
}

int main () {
	int t;
	cin>>t;
	int len_a, len_b;

	while (t--) {
		cin>>a;
		//cin.ignore(1000, '\n');
		cin>>b;

		if (a == "\0" && b == "\0") {
			cout<<0<<'\n';
			continue;
		}

		else if (a == "\0") {
			cout<<b.length()<<'\n';
			continue;
		}

		else if (b == "\0") {
			cout<<a.length()<<'\n';
			continue;
		} 

		len_a = a.length(); //strlen(a);
		len_b = b.length(); //strlen(b);

		for (int i = 0; i <= len_a; i++) {
			dp[i][0] = i;
		}

		for (int j = 0; j <= len_b; j++) {
			dp[0][j] = j;
		}

		for (int i = 1; i <= len_a; i++) {
			for (int j = 1; j <= len_b; j++) {
				if (a[i-1] == b[j-1])
					dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 0);
				else
					dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1);		
			}
		}
		cout<<dp[len_a][len_b]<<'\n';
	}
	return 0;
}
