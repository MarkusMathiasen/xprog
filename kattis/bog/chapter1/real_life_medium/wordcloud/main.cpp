#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int W, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int T = 1; true; T++) {
		cin >> W >> N;
		if (W == 0)
			break;
		vector<ii> words;
		int cm = 0;
		for (int i = 0; i < N; i++) {
			string s; int am; cin >> s >> am;
			if (am < 5)
				continue;
			words.push_back(ii((int)s.size(), am));
			cm = max(cm, am);
		}
		int lwidth = 0;
		int lheight = 0;
		int height = 0;
		for (ii word : words) {
			int lett = word.first;
			int freq = word.second;
			int pt = 8 + ceil(40 * (freq - 4) / (cm-4.0));
			int wordWidth = ceil(9 * lett * pt / 16.0);
			int space = (lwidth == 0 ? 0 : 10);
			if (lwidth+wordWidth+space <= W) {
				lwidth += wordWidth + space;
				lheight = max(lheight, pt);
			}
			else {
				height += lheight;
				lheight = pt;
				lwidth = wordWidth;
			}
		}
		printf("CLOUD %d: %d\n", T, height + lheight);
	}
}
