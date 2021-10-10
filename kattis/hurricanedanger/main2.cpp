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
vector<ii> c;

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
		c.assign(n, ii());
		for (int i = 0; i < n; i++){
			string s; cin >> s >> c[i].x >> c[i].y;
			m[i] = s;
		}
		double bestd = 1e9;
		vector<int> res;
		ii r;
		r.x = B.x-A.x; r.y = B.y-A.y;
		for (int i = 0; i < n; i++){
			double y, x;
			if (r.x == 0){
				x = A.x;
				y = c[i].y;
			}
			else if (r.y == 0){
				x = c[i].x;
				y = A.y;
			}
			else {
				y = (c[i].x*r.x*r.y);
				y += c[i].y*r.y*r.y;
				y += A.y*r.x*r.x;
				y -= A.x*r.x*r.y;
				y /= (r.x*r.x+r.y*r.y);

			x = r.x/(double)r.y*y+A.x/(double)r.x - A.y/(double)r.y;
			}
			//cout << "x: " << x << endl;
			//cout << "y: " << y << endl;
			double d = dist(c[i].x, c[i].y, x, y);
			if (d - 0.001 < bestd && d + 0.001 > bestd){
				res.push_back(i);
			}
			else if (d < bestd){
				res.assign(1, i);
				bestd = d;
			}	
		}
		for (int i = 0; i < (int)res.size(); i++)
			cout << m[res[i]] << " ";
		printf("\n");
	}
}
