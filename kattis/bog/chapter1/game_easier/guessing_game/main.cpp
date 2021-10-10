#include <bits/stdc++.h>
using namespace std;

vector<bool> tooHigh;
vector<int> guesses;
int g;

int main() {
	while (scanf("%d\n", &g), g != 0) {
		string ans; getline(cin, ans);
		if (ans == "too high") {
			tooHigh.push_back(true);
			guesses.push_back(g);
		}
		if (ans == "too low") {
			tooHigh.push_back(false);
			guesses.push_back(g);
		}
		if (ans == "right on") {
			bool honest = true;
			for (int i = 0; i < (int)tooHigh.size(); i++)
				honest &= tooHigh[i] == (guesses[i] > g) && guesses[i] != g;
			if (honest)
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			tooHigh.clear();
			guesses.clear();
		}
	}
}
