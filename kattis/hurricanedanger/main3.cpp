#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct ii{
	ll x;
	ll y;
};

int T, n;
ii A, B;
ii r;
map<int, string> m;
vector<ii> city;

double dist(int a, int b, double x, double y){
	double dx = a - x;
	double dy = b - y;
	dx *= dx;
	dy *= dy;
	return sqrt(dx+dy);
}

int main(){
	cin >> T;
	while (T--){
		cin >> A.x >> A.y >> B.x >> B.y;
		cin >> n;
		m.clear();
		city.assign(n, ii());
		for (int i = 0; i < n; i++){
			string s; cin >> s >> city[i].x >> city[i].y;
			m[i] = s;
		}
		double bestd = 1e9;
		vector<int> res;
		ii r;
		r.x = B.x-A.x; r.y = B.y-A.y;
		double a = 1/ (double) r.x;
		double b = 1/ (double) (-r.y);
		double c = A.y /(double) r.y - A.x / (double) r.x;
		for (int i = 0; i < n; i++){
			double d;
			if (r.y == 0)
				d = A.y - city[i].y;
			else if (r.x == 0)
				d = A.x - city[i].x;
			else {
				d = a*city[i].x+b*city[i].y+c;
				d /= sqrt(a*a+b*b);
			}
			if (d < 0) d = -d;
			if (d - 0.001 < bestd && d + 0.001 > bestd){
				res.push_back(i);
			}
			else if (d < bestd){
				res.assign(1, i);
				bestd = d;
			}	
			//cout << m[i] << ": " << d << endl;
		}
		for (int i = 0; i < (int)res.size(); i++)
			cout << m[res[i]] << " ";
		printf("\n");
	}
}
