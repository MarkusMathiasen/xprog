#include <bits/stdc++.h>

using namespace std;
#define dd pair<double, double>

int B, F;
vector<dd> taxes; // first is cap and second is tax
vector<dd> friends; // first is earnings and second is gift size

int main() {
	cin >> B;
	taxes.assign(B+1, dd(1e100, 0));
	for (int i = 0; i < B; i++) {
		cin >> taxes[i].first >> taxes[i].second;
		taxes[i].second /= 100;
		taxes[i].second = 1 - taxes[i].second;
	}
	cin >> taxes[B].second;
	taxes[B].second /= 100;
	taxes[B].second = 1 - taxes[B].second;
	B++;
	cin >> F;
	friends.assign(F, dd(0, 0));
	for (int i = 0; i < F; i++)
		cin >> friends[i].first >> friends[i].second;
	for (int f = 0; f < F; f++) {
		double curr = 0;
		double rema = friends[f].first;
		int t = 0;
		while ((taxes[t].first-curr)*taxes[t].second <= rema) {
			rema -= (taxes[t].first - curr)*taxes[t].second;
			curr = taxes[t].first;
			t++;
		}
		curr += rema / taxes[t].second;

		rema = friends[f].second;
		double res = 0;
		while ((taxes[t].first-curr)*taxes[t].second <= rema) {
			res += (taxes[t].first - curr) / taxes[t].second;
			rema -= (taxes[t].first-curr);
			curr = taxes[t].first;
			t++;
		}
		res += rema / taxes[t].second;
		printf("%.6f\n", res);

	}
}
