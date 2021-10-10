#include <bits/stdc++.h>
using namespace std;

map<string, string> m = {
	{"A#", "Bb"}, {"Bb", "A#"},
	{"C#", "Db"}, {"Db", "C#"},
	{"D#", "Eb"}, {"Eb", "D#"},
	{"F#", "Gb"}, {"Gb", "F#"},
	{"G#", "Ab"}, {"Ab", "G#"}
};

string a, b;
int T = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> a >> b) {
		printf("Case %d: ", T++);
		if (!m.count(a))
			printf("UNIQUE\n");
		else
			printf("%s %s\n", m[a].c_str(), b.c_str());
	}
}
