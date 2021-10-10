#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;

struct song {
	string name;
	ll f;
	ll o;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<song> v(n, song());
	for (ll i = 0; i < n; i++)
		cin >> v[i].f >> v[i].name, v[i].o = i+1;
	stable_sort(v.begin(), v.end(), [](song const& a, song const& b) {
		return a.f*a.o > b.f*b.o;
	});
	for (ll i = 0; i < m; i++)
		cout << v[i].name << "\n";
}
