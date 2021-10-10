#include <bits/stdc++.h>
using namespace std;

struct box {
	double x1;
	double y1;
	double x2;
	double y2;
	string size;
};

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n, n) {
		vector<box> boxes(n, box());
		for (int i = 0; i < n; i++)
			cin >> boxes[i].x1 >> boxes[i].y1 >> boxes[i].x2 >> boxes[i].y2 >> boxes[i].size;
		cin >> m;
		for (int i = 0; i < m; i++) {
			double x, y; string size; cin >> x >> y >> size;
			bool found = false;
			for (box b : boxes) {
				if (b.x1 <= x && x <= b.x2 && b.y1 <= y && y <= b.y2) {
					found = true;
					cout << size << " " << (size == b.size ? "correct" : b.size) << "\n";
				}
			}
			if (!found)
				cout << size << " " << "floor\n";
		}
		cout << "\n";
	}
}
