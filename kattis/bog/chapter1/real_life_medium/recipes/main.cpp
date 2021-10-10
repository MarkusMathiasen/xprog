#include <bits/stdc++.h>
using namespace std;
#define si pair<string int>

int T;
int R, P, D;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		vector<string> names;
		vector<double> perc;
		double mainWeight = -1;
		cin >> R >> P >> D;
		for (int i = 0; i < R; i++) {
			string n; double w; double p;
			cin >> n >> w >> p;
			names.push_back(n);
			perc.push_back(p);
			if (p == 100.0)
				mainWeight = w * D / P;
		}
		printf("Recipe # %d\n", t);
		for (int i = 0; i < R; i++)
			printf("%s %.1f\n", names[i].c_str(), mainWeight*perc[i]/100);
		for (int i = 0; i < 40; i++)
			printf("-");
		printf("\n");
	}
}
