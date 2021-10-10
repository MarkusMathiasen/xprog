#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct window {
	int number;
	int l; // left
	int r; // right
	int t; // top
	int b; // bottom
	window(int l, int r, int t, int b, int number) {
		this->l = l;
		this->r = r;
		this->t = t;
		this->b = b;
		this->number = number;
	}
};

int xmax, ymax;
vector<window> windows;
set<int> moved;

bool intersect(window& a, window& b) {
	return a.t >= b.b && a.b <= b.t && a.r >= b.l && a.l <= b.r;
}
bool intersect(window& a, int x, int y) {
	return a.l <= x && a.r >= x && a.t >= y && a.b <= y;
}
int findWindow(int x, int y) {
	for (int i = 0; i < (int)windows.size(); i++)
		if (intersect(windows[i], x, y))
			return i;
	return -1;
}

void movex(int index, int dx) {
	if (index >= (int)windows.size() || index < 0)
		return;
	window& a = windows[index];
	vector<int> movers;
	if (dx > 0) {
		window box(a.r+1, a.r+dx, a.t, a.b, -1);
		for (int i = 0; i < (int)windows.size(); i++)
			if (intersect(box, windows[i]))
				movers.push_back(i);
		sort(movers.begin(), movers.end(), [](int a, int b) {
			return windows[a].l <= windows[b].l;
		});
		for (int mover : movers)
			if (intersect(box, windows[mover]))
				movex(mover, box.r-windows[mover].l+1);
	}
	else if (dx < 0) {
		window box(a.l+dx, a.l-1, a.t, a.b, -1);
		for (int i = 0; i < (int) windows.size(); i++)
			if (intersect(box, windows[i]))
				movers.push_back(i);
		sort(movers.begin(), movers.end(), [](int a, int b) {
			return windows[a].r >= windows[b].r;
		});
		for (int mover : movers)
			if (intersect(box, windows[mover]))
				movex(mover, box.l - windows[mover].r-1);
	}
	a.l += dx;
	a.r += dx;
	moved.insert(index);
}

void movey(int index, int dy) {
	if (index >= (int)windows.size() || index < 0)
		return;
	window& a = windows[index];
	vector<int> movers;
	if (dy > 0) {
		window box(a.l, a.r, a.t+dy, a.t+1, -1);
		for (int i = 0; i < (int)windows.size(); i++)
			if (intersect(box, windows[i]))
				movers.push_back(i);
		sort(movers.begin(), movers.end(), [](int a, int b) {
			return windows[a].b <= windows[b].b;
		});
		for (int mover : movers)
			if (intersect(box, windows[mover]))
				movey(mover, box.t-windows[mover].b+1);
	}
	else if (dy < 0) {
		window box(a.l, a.r, a.b-1, a.b+dy, -1);
		for (int i = 0; i < (int)windows.size(); i++)
			if (intersect(box, windows[i]))
				movers.push_back(i);
		sort(movers.begin(), movers.end(), [](int a, int b) {
			return windows[a].t >= windows[b].t;
		});
		for (int mover : movers)
			if (intersect(box, windows[mover]))
				movey(mover, box.b - windows[mover].t-1);
	}
	a.t += dy;
	a.b += dy;
	moved.insert(index);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> xmax >> ymax;
	string cmd; int cnt = 0;
	while (cin >> cmd) {
		cnt++;
		if (cmd == "OPEN") {
			int x, y, w, h; cin >> x >> y >> w >> h;
			window a(x, x+w-1, y+h-1, y, cnt);
			bool space = true;
			for (window wind : windows)
				if (intersect(a, wind))
					space = false;
			if (space)
				windows.push_back(a);
			else
				printf("Command %d: OPEN - window does not fit\n", cnt);
		}
		else if (cmd == "CLOSE") {
			int x, y; cin >> x >> y;
			int index = findWindow(x, y);
			if (index == -1)
				printf("Command %d: CLOSE - no window at given position\n", cnt);
			else {
				auto it = windows.begin();
				for (int i = 0; i < index; i++)
					it++;
				windows.erase(it);
			}
		}
		else if (cmd == "RESIZE") {
			int x, y, w, h; cin >> x >> y >> w >> h;
			int index = findWindow(x, y);
			if (index == -1)
				printf("Command %d: RESIZE - no window at given position\n", cnt);
			else {
				if (index < 0 || index >= (int)windows.size())
					return 0;
				window& a = windows[index];
				window na(a.l, a.l+w-1, a.b+h-1, a.b, a.number);
				bool space = true;
				for (int i = 0; i < (int)windows.size(); i++) {
					if (i == index)
						continue;
					if (intersect(na, windows[i]))
						space = false;
				}
				if (space)
					windows[index] = na;
				else
					printf("Command %d: RESIZE - window does not fit\n", cnt);
			}
		}
		else if (cmd == "MOVE") {
			int x, y, dx, dy; cin >> x >> y >> dx >> dy;
			int index = findWindow(x, y);
			if (index == -1)
				printf("Command %d: MOVE - no window at given position\n", cnt);
			else {
				moved.clear();
				int rat = 0;
				if (dx) {
					movex(index, dx);
					int over = 0;
					int under = 0;
					for (int move : moved) {
						over = max(over, windows[move].r - (xmax-1));
						under = min(under, windows[move].l);
					}
					rat = -over-under;
					for (int move : moved) {
						windows[move].l += rat;
						windows[move].r += rat;
					}
				}
				if (dy) {
					movey(index, dy);
					int over = 0, under = 0;
					for (int move : moved) {
						over = max(over, windows[move].t - (ymax-1));
						under = min(under, windows[move].b);
					}
					rat = -over-under;
					for (int move : moved) {
						windows[move].t += rat;
						windows[move].b += rat;
					}
				}
				if (rat != 0)
					printf("Command %d: MOVE - moved %d instead of %d\n", cnt, abs(dx+dy+rat), abs(dx+dy));
			}
		}
		else
			return 0;
			//throw cmd;
	}
	printf("%d window(s):\n", (int)windows.size());
	sort(windows.begin(), windows.end(), [](window a, window b) {
		return a.number <= b.number;
	});
	for (window a : windows)
		printf("%d %d %d %d\n", a.l, a.b, a.r-a.l+1, a.t-a.b+1);
}
