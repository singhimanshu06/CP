#include <bits/stdc++.h>

using namespace std;

int max (int a, int b, int c) {
	return max(a, max(b,c));
}

int main () {
	int t;
	int h, w;

	cin>>t;

	while(t--) {
		int matrix[100][100];
		cin>>h>>w;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin>>matrix[i][j];
			}
		}

		int dp[100][100];

		for (int j = 0; j < w; j++) {
			dp[0][j] = matrix[0][j];
		}

		for (int i = 1; i < h; i++) {
			for (int j = 1; j < w; j++) {
				if (j == 0) 
					dp[i][j] = max(dp[i-1][j+1], dp[i-1][j]) + matrix[i][j];
				else if (j == w-1) 
					dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + matrix[i][j];
				else
					dp[i][j] = max(dp[i-1][j-1], dp[i-1][j+1], dp[i-1][j]) + matrix[i][j];
			}
		}

		int max_stn = dp[h-1][0];
		for (int j = 1; j < w; j++) {
			max_stn = dp[h-1][j] > max_stn ? dp[h-1][j] : max_stn;
		}
		cout<<max_stn<<'\n';
	}
	return 0;
}