#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		priority_queue<int> bid;
		priority_queue<int, vector<int>, greater<int>> ask;
		int stock = -1;
		while (n--) {
			string cmd, s; int amount, price; cin >> cmd >> amount >> s >> s >> price;
			if (cmd == "buy")
				for (int i = 0; i < amount; i++)
					bid.push(price);
			else if (cmd == "sell")
				for (int i = 0; i < amount; i++)
					ask.push(price);
			else throw cmd;
			while (!bid.empty() && !ask.empty() && bid.top() >= ask.top()) {
				stock = ask.top();
				bid.pop();
				ask.pop();
			}
			if (ask.empty())
				cout << "- ";
			else
				cout << ask.top() << " ";
			if (bid.empty())
				cout << "- ";
			else
				cout << bid.top() << " ";
			if (stock == -1)
				cout << "-\n";
			else
				cout << stock << "\n";
		}
	}
}
