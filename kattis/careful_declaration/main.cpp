#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

vector<string> l1, l2;
vector<vector<int>> dp;
vector<vector<ii>> nxt;

int calc(int a, int b) {
	if (dp[a][b] != -1)
		return dp[a][b];
	if (l1[a+1] == l2[b+1]) {
		nxt[a][b] = ii(a+1, b+1);
		dp[a][b] = calc(a+1, b+1)+1;
	}
	else if (calc(a+1, b) < calc(a, b+1)) {
		nxt[a][b] = ii(a+1, b);
		dp[a][b] = calc(a+1, b)+1;
	}
	else if (calc(a+1, b) > calc(a, b+1)) {
		nxt[a][b] = ii(a, b+1);
		dp[a][b] = calc(a, b+1)+1;
	}
	else if (l1[a+1] < l2[b+1]) {
		nxt[a][b] = ii(a+1, b);
		dp[a][b] = calc(a+1, b)+1;
	}
	else {
		nxt[a][b] = ii(a, b+1);
		dp[a][b] = calc(a, b+1)+1;
	}
	return dp[a][b];
}

int main() {
	l1.assign(2, "");
	cin >> l1[1];
	while (l1.back() != ".") {
		string s; cin >> s;
		l1.push_back(s);
	}
	while (l1.size() > 2) {
		l2.assign(2, ""); cin >> l2[1];
		while (l2.back() != ".") {
			string s; cin >> s;
			l2.push_back(s);
		}
		dp.assign(l1.size()+1, vector<int>(l2.size()+1, -1));
		nxt.assign(l1.size()+1, vector<ii>(l2.size()+1, ii(0, 0)));
		for (int i = 0; i <= (int)l1.size(); i++) {
			nxt[i][l2.size()-1] = ii(i+1, l2.size()-1);
			dp[i][l2.size()-1] = l1.size()-i-1;
		}
		for (int i = 0; i <= (int)l2.size(); i++) {
			nxt[l1.size()-1][i] = ii(l1.size()-1, i+1);
			dp[l1.size()-1][i] = l2.size()-i-1;
		}
		calc(0, 0);
		int a = 0;
		int b = 0;
		while (a != (int)l1.size()-1 || b != (int)l2.size()-1) {
			if (nxt[a][b] == ii(a+1, b)) {
				cout << l1[a+1] << " ";
				a++;
			}
			else if (nxt[a][b] == ii(a, b+1)) {
				cout << l2[b+1] << " ";
				b++;
			}
			else if (nxt[a][b] == ii(a+1, b+1)) {
				cout << l1[a+1] << " ";
				a++;
				b++;
			}
		}
		cout << endl;
		l1.assign(2, "");
		cin >> l1[1];
		while (l1.back() != ".") {
			string s; cin >> s;
			l1.push_back(s);
		}
	}

}
