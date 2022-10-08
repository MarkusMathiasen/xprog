#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> A;
vector<string> res;

void print_unique() {
	printf("UNIQUE\n");
	for (string& s : res)
		printf("%s\n", s.c_str());
}

void print_many() {
	printf("MANY\n");
}

void print_none() {
	printf("NONE\n");
}

bool verify() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				continue;
			else if (res[i] + res[j] != A[i][j])
				return false;
	return true;
}

bool cmp(string& a, string& b, int x) {
	for (int i = 0; i < x/2+1; i++)
		if (a[i] != b[b.size()-x+i] || a[x-i-1] != b[b.size()-i-1])
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	A.assign(n, vector<string>(n, ""));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	res.assign(n, "");
	if (n == 2) {
		string& a = A[0][1];
		string& b = A[1][0];
		int l = a.size();
		if (l != (int)b.size() || l < 2) {
			print_none();
			return 0;
		}
		vector<int> a_cnt(26, 0), b_cnt(26, 0);
		for (char c : a)
			a_cnt[c-'a']++;
		for (char c : b)
			b_cnt[c-'a']++;
		for (int i = 0; i < 26; i++)
			if (a_cnt[i] != b_cnt[i]) {
				print_none();
				return 0;
			}
		string res_0, res_1;
		bool found = false;
		for (int i = 1; i < l; i++) {
			if (cmp(a, b, i) && cmp(b, a, l-i)) {
				if (found) {
					print_many();
					return 0;
				}
				found = true;
				res_0 = a.substr(0, i);
				res_1 = b.substr(0, l-i);
			}
		}
		if (found) {
			res = {res_0, res_1};
			print_unique();
		} else {
			print_none();
		}
	} else if (n > 2) {
		int l01 = A[0][1].size();
		int l02 = A[0][2].size();
		int l12 = A[1][2].size();
		int l2 = (l12 - l01 + l02)/2;
		if (l2 < 1) {
			print_none();
			return 0;
		}
		if (l02 <= l2) {
			print_none();
			return 0;
		}
		res[2] = A[0][2].substr(l02-l2, l2);
		for (int i = 0; i < n; i++) {
			if (i == 2)
				continue;
			if ((int)A[2][i].size() <= l2) {
				print_none();
				return 0;
			}
			res[i] = A[2][i].substr(l2, A[2][i].size()-l2);
		}
		if (!verify()) {
			print_none();
			return 0;
		}
		print_unique();
		return 0;
	}
}
