#include <bits/stdc++.h>
using namespace std;

int n;
set<char> v({'a', 'e', 'i', 'o', 'u', 'y'});

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n) {
		if (n == 0)
			break;
		string bw = "";
		int bc = -1;
		while (n--) {
			string w; cin >> w;
			int count = 0;
			for (int i = 1; i < (int)w.size(); i++)
				if (w[i] == w[i-1] && v.count(w[i]))
					count++;
			if (count > bc)
				bw = w, bc = count;
		}
		cout << bw << endl;
	}
}
