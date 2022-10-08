#include <bits/stdc++.h>
using namespace std;

int n; 
vector<vector<string>> A;
vector<string> res;

bool cmp_interval(string& a, string& b, int l) {
	for (int i = 0; i < l; i++)
		if (a[i] != b[b.size()-l+i])
			return false;
	return true;
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

void print_solution() {
	printf("UNIQUE\n");
	for (string& s : res)
		printf("%s\n", s.c_str());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	A.assign(n, vector<string>(n, ""));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	if (n == 2) {
		string& a = A[0][1];
		string& b = A[1][0];
		if (a.size() != b.size() || a.size() < 2)
			goto none;
		int l = a.size();
		string res_a, res_b;
		int res_n = 0;
		for (int i = 1; i < l; i++) {
			if (cmp_interval(a, b, i)
				&& cmp_interval(b, a, l-i)) {
				res_n++;
				if (res_n > 1)
					break;
				res_a = a.substr(0, i);
				res_b = a.substr(i, l-i);
			}
		}
		if (res_n == 0)
			goto none;
		else if (res_n == 1)
			res = {res_a, res_b},
			print_solution();
		else
			printf("MANY\n");
		return 0;
	}
	else {
		int l12 = A[0][1].size();
		int l13 = A[0][2].size();
		int l23 = A[1][2].size();
		int l3 = (l23 - l12 + l13)/2;
		if (l3 < 1)
			goto none;
		res.assign(n, "");
		if ((int)A[2][0].size() <= l3)
			goto none;
		res[2] = A[2][0].substr(0, l3);
		for (int i = 0; i < n; i++) {
			if (i == 2)
				continue;
			if ((int)A[2][i].size() <= l3)
				goto none;
			res[i] = A[2][i].substr(l3, A[2][i].size()-l3);
		}
		if (!verify())
			goto none;
		print_solution();
		return 0;
	}
none:
	printf("NONE\n");
	return 0;
}
