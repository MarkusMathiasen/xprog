#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define dd pair<double, double>

int T, n;
vector<ii> cmd;
const double pi = 3.141592653589793238463;

dd go(int dir, int am, dd pos){
	double ang = dir/(double)180 * pi;
	double dx = cos(ang)*am;
	double dy = sin(ang)*am;
	pos.first += dx;
	pos.second += dy;
	return pos;
}
int turn(int dir, int am){
	dir += am;
	if (dir < 0) dir += 360;
	if (dir > 359) dir -= 360;
	return dir;
}

dd simulate(int mis){
	int dir = 0;
	dd pos(0, 0);
	for (int i = 0; i < (int)cmd.size(); i++){
		int c = cmd[i].first;
		int am = cmd[i].second;
		if (am == -1) am = mis;
		if (c == 1)
			pos = go(dir, am, pos);
		if (c == 2)
			pos = go(dir, -am, pos);
		if (c == 3)
			dir = turn(dir, am);
		if (c == 4)
			dir = turn(dir, -am);
	}
	return pos;
}

bool atEnd(dd at, double fact){
	if (at.first-fact < 0 && at.first+fact > 0 &&
			at.second-fact < 0 && at.second+fact > 0){
		return true;
	}
	return false;
}

int main(){
	cin >> T;
	while (T--){
		cin >> n;
		cmd.assign(n, ii());
		bool misTurn = false;
		for (int i = 0; i < n; i++){
			string s, l;
			cin >> s >> l;
			if (l != "?")
				cmd[i].second = stoi(l);
			else{
				cmd[i].second = -1;
				if (s == "lt" || s == "rt")
					misTurn = true;
			}
			if (s == "fd")
				cmd[i].first = 1;
			if (s == "bk")
				cmd[i].first = 2;
			if (s == "lt")
				cmd[i].first = 3;
			if (s == "rt")
				cmd[i].first = 4;
		}
		int res = -1;
		if (misTurn){
			double closestVal = 1e18;
			int closest = 0;
			for (int i = 0; i < 360; i++){
				dd at = simulate(i);
				double ndist = sqrt(at.first*at.first
						+at.second*at.second);
				if (ndist < closestVal){
					closestVal = ndist;
					closest = i;
				}
			}
			res = closest;
		}
		else {
			dd end = simulate(0);
			double eres = sqrt(end.first*end.first+end.second*end.second);
			res = round(eres);
		}
		cout << res << endl;
	}
}
