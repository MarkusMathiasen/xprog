#include <bits/stdc++.h>
using namespace std;

struct team {
	int team_number;
	int solved;
	int penalty;
	team(int team_number, int solved, int penalty)
		: team_number(team_number), solved(solved), penalty(penalty) {}
	bool operator < (const team& a) const {
		if (solved != a.solved)
			return solved > a.solved;
		if (penalty != a.penalty)
			return penalty < a.penalty;
		return team_number < a.team_number;
	}
};

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<team, null_type, less<team>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	ost standings;
	vector<team> teams = {team(0, 0, 0)};
	for (int i = 0; i < n; i++) {
		standings.insert(team(i+1, 0, 0));
		teams.push_back(team(i+1, 0, 0));
	}
	while (m--) {
		int t, p; scanf("%d%d", &t, &p);
		standings.erase(teams[t]);
		teams[t].solved++;
		teams[t].penalty += p;
		standings.insert(teams[t]);
		int rank = standings.order_of_key(teams[1]);
		printf("%d\n", rank+1);
	}
}
