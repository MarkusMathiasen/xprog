#include <bits/stdc++.h>
using namespace std;
#define is pair<int, string>

struct Compare {
	bool operator()(const is& a, const is& b) {
		if (a.first != b.first)
			return a.first < b.first;
		else
			return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	unordered_map<string, int> m;
	queue<is> q;
	int day = 0;
	while (cin >> s) {
		if (s == "<text>") {
			day++;
			while (cin >> s, s != "</text>")
				if ((int)s.size() >= 4) 
					m[s]++, q.push(is(day+7, s));
		}
		else if (s == "<top") {
			while (q.front().first <= day)
				m[q.front().second]--, q.pop();
			int t; cin >> t >> s;
			printf("<top %d>\n", t);
			priority_queue<is, vector<is>, Compare> pq;
			for (auto& [k,v] : m)
				pq.push(is(v, k));
			int prev = 0;
			for (int i = 0; i < t; i++) {
				auto& [d,w] = pq.top();
				printf("%s %d\n", w.c_str(), d);
				prev = d;
				pq.pop();
			}
			while (pq.size() && pq.top().first == prev) {
				auto& [d,w] = pq.top();
				printf("%s %d\n", w.c_str(), d);
				pq.pop();
			}
			printf("</top>\n");
		}
		else throw s;
	}
}
