#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string, string> unis;
	vector<string> uniList;
	int n; cin >> n;
	while (n--) {
		string uni, team; cin >> uni >> team;
		if (!unis.count(uni)) {
			unis[uni] = team;
			uniList.push_back(uni);
		}
	}

	for (int i = 0; i < 12; i++) {
		string uni = uniList[i];
		cout << uni << " " << unis[uni] << "\n";
	}

}
