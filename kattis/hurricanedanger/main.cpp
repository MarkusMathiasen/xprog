#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<ll, ll>

int T, n;
int x1, x2, y_1, y2;
ii r;
map<int, string> m;
vector<ii> c;

int main(){
	cin >> T;
	while (T--){
		cin >> x1 >> y_1 >> x2 >> y2;
		cin >> n;
		m.clear();
		c.assign(n, ii(0, 0));
		for (int i = 0; i < n; i++){
			string s; cin >> s >> c[i].first >> c[i].second;
			m[i] = s;
		}
		ll dist = (ll)4e18;
		vector<int> res;
		ii r(x2-x1, y2-y_1);
		for (int i = 0; i < n; i++){
			ll att = c[i].first*r.second+c[i].second*r.first;
			if (c[i].first*r.second
					-c[i].second*r.first
					+y_1*r.first
					-x1*r.second
					== 0)
				att = 0;
			if (att < dist){
				dist = att;
				res.assign(1, i);
			}
			else if (att == dist)
				res.push_back(i);
		}
		for (int i = 0; i < (int)res.size(); i++)
			cout << m[res[i]] << " ";
		printf("\n");
	}
}
