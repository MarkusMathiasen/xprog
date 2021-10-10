#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		queue<int> q;
		priority_queue<int> pq;
		stack<int> s;
		bool isq = true, ispq = true, iss = true;
		for (int i = 0; i < n; i++) {
			int cmd, x; scanf("%d%d", &cmd, &x);
			if (cmd == 1) {
				if (isq)
					q.push(x);
				if (ispq)
					pq.push(x);
				if (iss)
					s.push(x);
			}
			else if (cmd == 2) {
				isq &= !q.empty() && q.front() == x;
				if (isq)
					q.pop();
				ispq &= !pq.empty() && pq.top() == x;
				if (ispq)
					pq.pop();
				iss &= !s.empty() && s.top() == x;
				if (iss)
					s.pop();
			}
			else throw cmd;
		}
		if (isq && !ispq && !iss)
			printf("queue\n");
		else if (!isq && ispq && !iss)
			printf("priority queue\n");
		else if (!isq && !ispq && iss)
			printf("stack\n");
		else if (isq || ispq || iss)
			printf("not sure\n");
		else
			printf("impossible\n");
	}
}
