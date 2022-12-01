#include <bits/stdc++.h>
using namespace std;

struct sock {
	int l = 0;
	int r = 0;
	int any = 0;
};

map<string, sock> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int sum = 0;
	while (n--) {
		string name, type; int amount; cin >> name >> type >> amount;
		sum += amount;
		if (type == "left")
			m[name].l = amount;
		else if (type == "right")
			m[name].r = amount;
		else if (type == "any")
			m[name].any = amount;
		else
			throw type;
	}
	int res = 0;
	for (auto& [t,s] : m)
		res += max(max(s.l, s.r), 1);
	if (sum != res)
		printf("%d\n", res+1);
	else
		printf("impossible\n");
}
