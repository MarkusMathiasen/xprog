#include <bits/stdc++.h>
using namespace std;

int speed = 0;
double dist = 0;
int t = 0;

int main() {
	ios_base::sync_with_stdio(false),
	cin.tie(NULL);
	string line;
	while (getline(cin, line), line != "") {
		if ((int)line.size() > 8) {
			int h, m, s, sp; sscanf(line.c_str(), "%d:%d:%d %d", &h, &m, &s, &sp);
			int tim = h*60*60 + m*60 + s;
			dist += speed * (tim - t)/(double)(60*60);
			t = tim;
			speed = sp;
		}  else {
			int h, m, s; sscanf(line.c_str(), "%d:%d:%d", &h, &m, &s);
			int tim = h*60*60 + m*60 + s;
			dist += speed * (tim - t)/(double)(60*60);
			t = tim;
			printf("%02d:%02d:%02d %.2lf km\n", h, m, s, dist);
		}
	}
}
