#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<int, int> m;
vector<pii> beacons, sensors;
vi dist;


int max_c = 4000000;

bool check_point(int x, int y) {
    if (x < 0 || x > max_c || y < 0 || y > max_c) return false;
    rep(i, 0, sz(beacons)) {
        int dist_sensor = abs(sensors[i].first - x) + abs(sensors[i].second - y);
        if (dist_sensor <= dist[i]) return false;
    }
    return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s; ss >> s >> s >> s;
        int x_sensor; sscanf(s.c_str(), "x=%d,", &x_sensor);
        ss >> s;
        int y_sensor; sscanf(s.c_str(), "y=%d:", &y_sensor);
        int x_beacon, y_beacon;
        ss >> s >> s >> s >> s >> s;
        sscanf(s.c_str(), "x=%d,", &x_beacon);
        ss >> s;
        sscanf(s.c_str(), "y=%d", &y_beacon);
        beacons.push_back({x_beacon, y_beacon});
        sensors.push_back({x_sensor, y_sensor});
        int dx = abs(x_sensor - x_beacon);
        int dy = abs(y_sensor - y_beacon);
        dist.push_back(dx + dy);
    }
    pii res = {-1, -1};
    rep(i, 0, sz(beacons)) {
        int x = sensors[i].first;
        int y = sensors[i].second;
        rep(dy, -dist[i]-1, dist[i]+2) {
            int dx = dist[i]+1 - abs(dy);
            if (check_point(x-dx, y+dy)) {
                res = {x-dx, y+dy};
                break;
            } else if (check_point(x+dx, y+dy)) {
                res = {x+dx, y+dy};
                break;
            }
        }
        if (res != pii(-1, -1)) break;
    }
    printf("%lld\n", (ll)res.first * 4000000LL + (ll)res.second);
}
