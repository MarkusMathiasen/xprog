#include <bits/stdc++.h>
using namespace std;
#define M 1000000007ll
#define P 250132ll
typedef long long ll;
typedef pair<int, int> ii;

string s, sub;
deque<ll> qs[256];
vector<ll> p;
ll N;

void addLetter(ll& h, ll pos) {
	deque<ll>& q = qs[0 | s[pos]];
	h = (h*P + (q.empty() ? N : pos - q.back())) % M;
	q.push_back(pos);
}

void removeLetter(ll& h, ll pos) {
	deque<ll>& q = qs[0|s[pos]];
	q.pop_front();
	h = ((h - N*p[N-1])%M+M)%M;
	if (!q.empty()) {
		ll j = q.front();
		h = ((h - (j-pos)*p[(pos + N - 1) - j])%M+M)%M;
		h = (h + N*p[(pos+N-1)-j])%M;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> sub;
	// calc hsub
	N = sub.size();
	vector<ll> nsub(N, 0);
	vector<int> prev(256, -1);
	for (int i = 0; i < N; i++)
		nsub[i] = prev[sub[i]] != -1 ? i - prev[sub[i]] : N,
		prev[sub[i]] = i;
	ll hsub = 0;
	for (ll x : nsub)
		hsub = (hsub*P + x) % M;
	// prepare p
	p.assign(N, 1);
	for (int i = 1; i < N; i++)
		p[i] = p[i-1]*P % M;
	// algo
	ll h = 0;
	int i = 0;
	for (; i < N-1; i++)
		addLetter(h, i);
	int cres = 0;
	int pres = -1;
	for (; i < (int)s.size(); i++) {
		addLetter(h, i);
		if (h == hsub)
			cres++,
			pres = i-N+1;
		removeLetter(h, i-N+1);
	}
	if (cres != 1)
		printf("%d\n", cres);
	else
		printf("%s\n", s.substr(pres, N).c_str());
}
