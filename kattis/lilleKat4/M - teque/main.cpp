#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> f, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--) {
		string cmd;
		int x;
		cin >> cmd >> x;
		if (cmd == "push_back")
			s.push_back(x);
		else if (cmd == "push_front")
			f.push_front(x);
		else if (cmd == "push_middle") {
			while (s.size() < f.size()) {
				s.push_front(f.back());
				f.pop_back();
			}
			while (f.size() < s.size()) {
				f.push_back(s.front());
				s.pop_front();
			}
			s.push_front(x);
		}
		else if (cmd == "get") {
			if (x < f.size())
				cout << f[x] << "\n";
			else
				cout << s[x-f.size()] << "\n";
		}
	}
}
