#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct state {
    int rob_ore, rob_clay, rob_obs, rob_geo;
    int ore, clay, obs, geo;
    int minutes;
    bool operator<(const state& o) const {
        if (minutes != o.minutes) return minutes > o.minutes;
        if (rob_ore != o.rob_ore) return rob_ore < o.rob_ore;
        if (rob_clay != o.rob_clay) return rob_clay < o.rob_clay;
        if (rob_obs != o.rob_obs) return rob_obs < o.rob_obs;
        if (rob_geo != o.rob_geo) return rob_geo < o.rob_geo;
        if (ore != o.ore) return ore < o.ore;
        if (clay != o.clay) return clay < o.clay;
        if (obs != o.obs) return obs < o.obs;
        return geo < o.geo;
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    int id, ore_p, clay_p, obs_ore_p, obs_clay_p, geo_ore_p, geo_obs_p;
    long long result = 1;
    while (scanf(" Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.",
            &id, &ore_p, &clay_p, &obs_ore_p, &obs_clay_p, &geo_ore_p, &geo_obs_p) != EOF) {
        if (id > 3) break;
        printf("id: %d\n", id);
        set<state> vis;
        state init = {1, 0, 0, 0, 0, 0, 0, 0, 0};
        queue<state> q;
        q.push(init);
        int res = 0;
        while (!q.empty()) {
            state s = q.front(); q.pop();
            if (vis.count(s)) continue;
            vis.insert(s);
            //res = max(res, s.geo+s.rob_geo*(s.minutes-24));
            if (s.minutes == 32) {
                res = max(res, s.geo);
                continue;
            }
            if (s.ore >= geo_ore_p && s.obs >= geo_obs_p)
                q.push({s.rob_ore, s.rob_clay, s.rob_obs, s.rob_geo+1, s.ore+s.rob_ore-geo_ore_p, s.clay+s.rob_clay, s.obs+s.rob_obs-geo_obs_p, s.geo+s.rob_geo, s.minutes+1});
            if (s.ore >= obs_ore_p && s.clay >= obs_clay_p)
                q.push({s.rob_ore, s.rob_clay, s.rob_obs+1, s.rob_geo, s.ore+s.rob_ore-obs_ore_p, s.clay+s.rob_clay-obs_clay_p, s.obs+s.rob_obs, s.geo+s.rob_geo, s.minutes+1});
            if (s.ore >= clay_p && s.rob_clay < obs_clay_p)
                q.push({s.rob_ore, s.rob_clay+1, s.rob_obs, s.rob_geo, s.ore+s.rob_ore-clay_p, s.clay+s.rob_clay, s.obs+s.rob_obs, s.geo+s.rob_geo, s.minutes+1});
            if (s.ore >= ore_p && s.rob_ore < 4)
                q.push({s.rob_ore+1, s.rob_clay, s.rob_obs, s.rob_geo, s.ore+s.rob_ore-ore_p, s.clay+s.rob_clay, s.obs+s.rob_obs, s.geo+s.rob_geo, s.minutes+1});
            q.push({s.rob_ore, s.rob_clay, s.rob_obs, s.rob_geo, s.ore+s.rob_ore, s.clay+s.rob_clay, s.obs+s.rob_obs, s.geo+s.rob_geo, s.minutes+1});
        }
        printf("res: %d\n", res);
        result *= res;
    }
    printf("%lld\n", result);
}
