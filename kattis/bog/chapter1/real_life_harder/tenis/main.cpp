#include <bits/stdc++.h>
using namespace std;

int N;
string p1, p2;
stringstream ss;
int a, b;

void fed(int a1, int a2, bool& valid) {
	if (p1 == "federer")
		valid &= a1 > a2;
	if (p2 == "federer")
		valid &= a1 < a2;
}

int check(int a1, int a2, bool& valid) {
	fed(a1, a2, valid);
	int A = max(a1, a2), a = min(a1, a2);
	valid &= (A == 7 && a+2 >= A) || (a+2 <= A && A == 6);
	return a1 > a2 ? 1 : 2;
}

void getInput() {
	string w; ss >> w;
	sscanf(w.c_str(), "%d:%d", &a, &b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p1 >> p2 >> N;
	string line; getline(cin, line);
	while (getline(cin, line), N--) {
		ss = stringstream(line);
		bool valid = true;
		int wins = 0;
		a = b = 0;
		if (count(line.begin(), line.end(), ':') < 2)
			valid = false;
		for (int i = 0; i < 2 && valid; i++) {
			getInput();
			wins += check(a, b, valid);
		}
		if (wins == 3) {
			if (count(line.begin(), line.end(), ':') == 3) {
				getInput();
				fed(a, b, valid);
				int A = max(a, b);
				int B = min(a, b);
				valid &= (B >= 4 && B+2 == A) || (A == 6 && B+2 <= A);
			} else
				valid = false;
		} else
			valid &= count(line.begin(), line.end(), ':') == 2;
		printf(valid ? "da\n" : "ne\n");
			
	}
}
