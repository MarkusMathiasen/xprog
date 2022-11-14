#include <bits/stdc++.h>
using namespace std;

int n, r, t;
unordered_map<string, int> m;
int am[5], goal[5];
int rec[5][5];
stack<int> res;

bool is_done() {
	bool res = true;
	for (int i = 0; i < n; i++)
		res &= am[i] >= goal[i];
	return res;
}

bool is_valid(int i) {
	bool val = true;
	for (int j = 0; j < n; j++)
		val &= am[j] >= -rec[i][j];
	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> t;
	for (int i = 0; i < n; i++) {
		string name; int a, b; cin >> name >> a >> b;
		m[name] = i;
		am[i] = a;
		goal[i] = b;
	}
	string line;
	getline(cin, line);
	for (int i = 0; i < r; i++) {
		getline(cin, line);
		stringstream ss(line);
		int diff; string name;
		while (ss >> diff >> name)
			rec[i][m[name]] = diff;
	}
	int i = 0;
	while (!is_done()) {
		if ((int)res.size() == t)
			goto stuck;
		for (i = 0; i < r; i++) {
			if (is_valid(i)) {
				res.push(i);
				for (int j = 0; j < n; j++)
					am[j] += rec[i][j];
				goto end;
			}
cont:;
		}
stuck:
		if (res.empty())
			break;
		for (int j = 0; j < n; j++)
			am[j] -= rec[res.top()][j];
		i = res.top();
		res.pop();
		goto cont;
end:;
	}
	if (!res.empty()) {
		stack<int> real_res;
		while (!res.empty())
			real_res.push(res.top()),
			res.pop();
		while (!real_res.empty())
			printf("%d ", real_res.top()+1),
			real_res.pop();
		printf("\n");
	}
	else
		printf("sad customers\n");
}
