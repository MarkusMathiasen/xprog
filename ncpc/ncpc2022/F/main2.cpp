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

vector<int> b;

void kmp_pre(string& sub) {
	b.assign(sub.size()+1, -1);
	int j = -1, i = 0;
	while (i < (int)sub.size()) {
		while (j >= 0 && sub[j] != sub[i])
			j = b[j];
		j++, i++;
		b[i] = j;
	}
}

void kmp_search(string& s, string& sub, vector<int>& res) {
	int i = 0, j = -1;
	while (i < (int)s.size()-1) {
		while (j >= 0 && s[i] != sub[j])
			j = b[j];
		j++, i++;
		if (j == (int)sub.size())
			res.push_back(i-j);
	}
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
		string aa = a + a;
		vector<int> idx;
		kmp_pre(b);
		kmp_search(aa, b, idx);
		if ((int)idx.size() > 1)
			print_many();
		else if ((int)idx.size() == 1) {
			res = {a.substr(0, idx[0]), a.substr(idx[0])};
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
