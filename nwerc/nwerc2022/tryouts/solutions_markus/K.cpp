#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	int biggest_lead = 0;
	int lead_to_Y = 0;
	int longest_streak = 0;
	int streak_to_Y = 0;
	int curr_streak = 0;
	int curr_streak_to_Y = 0;
	int y_points = 0, n_points = 0;
	while (N--) {
		string s; cin >> s;
		if (s == "Yraglac") {
			y_points++;
			int new_lead = y_points - n_points;
			if (new_lead > biggest_lead) {
				biggest_lead = new_lead;
				lead_to_Y = 1;
			} else if (new_lead == biggest_lead && lead_to_Y == -1) {
				lead_to_Y = 0;
			}
			if (curr_streak_to_Y == 1) {
				curr_streak++;
			} else {
				curr_streak = 1;
				curr_streak_to_Y = 1;
			}
			if (curr_streak > longest_streak) {
				longest_streak = curr_streak;
				streak_to_Y = 1;
			} else if (curr_streak == longest_streak && streak_to_Y == -1) {
				streak_to_Y = 0;
			}
		}
		else {
			n_points++;
			int new_lead = n_points - y_points;
			if (new_lead > biggest_lead) {
				biggest_lead = new_lead;
				lead_to_Y = -1;
			} else if (new_lead == biggest_lead && lead_to_Y == 1) {
				lead_to_Y = 0;
			}
			if (curr_streak_to_Y == -1) {
				curr_streak++;
			} else {
				curr_streak = 1;
				curr_streak_to_Y = -1;
			}
			if (curr_streak > longest_streak) {
				longest_streak = curr_streak;
				streak_to_Y = -1;
			} else if (curr_streak == longest_streak && streak_to_Y == 1) {
				streak_to_Y = 0;
			}
		}
	}
	printf("%s\n", streak_to_Y == lead_to_Y ? "Agree" : "Disagree");
}
