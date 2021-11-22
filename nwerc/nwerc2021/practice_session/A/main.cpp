#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

vector<ii> obs;
ll n, low, high, length;

int main() {
	scanf("%lld", &n);
	obs.assign(n, ii());
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &obs[i].first, &obs[i].second);
	sort(obs.begin(), obs.end());
	high = low = obs[0].second;
	length = 0;
	ll tim = obs[0].first;
	for (int i = 1; i < n; i++) {
		ll nTim = obs[i].first;
		ll nPos = obs[i].second;
		if (nPos-high > nTim - tim) { // cannot reach to the right
			length += (nPos-high) - (nTim-tim);
			high = nPos;
			low = high - length;
		}
		else if (low - nPos > nTim - tim) { // cannot reach to the left
			length += (low-nPos) - (nTim-tim);
			low = nPos;
			high = nPos + length;
		}
		else if (obs[i-1].second - nPos >= 0) { // can reach to the left
			low = max(nPos-length, low - (nTim-tim));
			high = min(nPos+length, high + (nTim-tim));
		}
		else if (obs[i-1].second - nPos < 0) { // can reach to the right
			high = min(nPos+length, high + (nTim-tim));
			low = max(nPos-length, low - (nTim-tim));
		}
		else assert(false);
		tim = nTim;
	}
	cout << length << endl;
}
