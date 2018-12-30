#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll stalls[100001];
ll n, c;

ll fit_cows(ll mid) {
	ll prev = stalls[0];
	ll count = 1;
	for (ll j = 1; j < n; j++) {
		if (stalls[j] - prev >= mid) {
			count++;
			prev = stalls[j];
		}
	}
	if (count >= c) {
		return 1;
	} else {
		return 0;
	}
}

ll binary_search (ll lo, ll hi) 
{
	ll mid;
	ll ans = 0;
	while (lo <= hi) {
		mid = lo + (hi - lo)/2;

		if (fit_cows(mid)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}

int main () {
	int t;
	ll res;

	cin>>t;
	while (t--) {
		cin>>n>>c;
		for (ll i = 0; i < n; i++) {
			cin>>stalls[i];
		}

		sort(stalls, stalls + n);

		ll hi = stalls[n-1] - stalls[0];
		ll lo = 0;

		res = binary_search(lo, hi);

		cout<<res<<'\n';
	}
}
