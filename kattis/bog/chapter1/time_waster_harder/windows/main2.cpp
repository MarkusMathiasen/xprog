#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

struct window {
	int l;
	int r;
	int t;
	int b;
	window(int l, int r, int t, int b) {
		this->l = l;
		this->r = r;
		this->t = t;
		this->b = b;
	}
};
int xmax, ymax;
vector<window> windows;

bool intersect(window& a, window& b) {
	return a.t >= b.b && b.t >= a.b && a.r >= b.l && b.r >= a.l;
}
bool intersect(window& a, int x, int y) {
	return a.l <= x && x <= a.r && a.b <= y && y <= a.t;
}

int findWindow(int x, int y) {
	for (int i = 0; i < (int)windows.size(); i++)
		if (intersect(windows[i], x, y))
			return i;
	return -1;
}

map<int, int> moved;

void movex(int index, int dx) {
	window& a = windows[index];
	queue<int> q;
	if (dx > 0) {
		window box(a.r+1, a.r+dx, a.t, a.b);
		for (int i = 0; i < (int)windows.size(); i++)
			if (intersect(box, windows[i]))
				q.push(i);
		while (!q.empty()) {
			int nxt = q.front(); q.pop();
			if (intersect(box, windows[nxt]))
				movex(nxt, box.r+1 - windows[nxt].l); //recursive
		}
	}
	else {
		window box(a.l+dx, a.l-1, a.t, a.b);
		for (int i = 0; i < (int)windows.size(); i++)
			if (intersect(box, windows[i]))
				q.push(i);
		while (!q.empty()) {
			int nxt = q.front(); q.pop();
			if (intersect(box, windows[nxt]))
				movex(nxt, box.l-1 - windows[nxt].r); //recursive
		}
	}
	a.l += dx;
	a.r += dx;
	moved[index] += dx;
}
void movey(int index, int dy) {
	window& a = windows[index];
	queue<int> q;
	if (dy > 0) {
		window box(a.l, a.r, a.t+dy, a.t+1);
		for (int i = 0; i < (int)windows.size(); i++)
			if (intersect(box, windows[i]))
				q.push(i);
		while (!q.empty()) {
			int nxt = q.front(); q.pop();
			if (intersect(box, windows[nxt]))
				movey(nxt, box.t+1 - windows[nxt].b); //recursive
		}
	}
	else {
		window box(a.l, a.r, a.b-1, a.b+dy);
		for (int i = 0; i < (int)windows.size(); i++)
			if (intersect(box, windows[i]))
				q.push(i);
		while (!q.empty()) {
			int nxt = q.front(); q.pop();
			if (intersect(box, windows[nxt]))
				movey(nxt, box.b-1 - windows[nxt].t); //recursive
		}
	}
	a.t += dy;
	a.b += dy;
	moved[index] += dy;
}

int main() {
	ios_base::sync_with_stdio(false),
	cin.tie(NULL);
	cin >> xmax >> ymax;
	string cmd; int cnt = 0;
	while (cin >> cmd) {
		cnt++;
		if (cmd == "OPEN") {
			int x, y, w, h; cin >> x >> y >> w >> h;
			window a(x, x+w-1, y+h-1, y);
			bool room  = true;
			for (window b : windows)
				if (intersect(a, b))
					room = false;
			if (a.l < 0 || a.r >= xmax || a.b < 0 || a.t >= ymax)
				room = false;
			if (room)
				windows.push_back(a);
			else
				printf("Command %d: OPEN - window does not fit\n", cnt);
		}
		else if (cmd == "CLOSE") {
			int x, y; cin >> x >> y;
			int index = findWindow(x, y);
			if (index == -1)
				printf("Command %d: CLOSE - no window at given position\n", cnt);
			else
				windows.erase(windows.begin()+index);
		}
		else if (cmd == "RESIZE") {
			int x, y, w, h; cin >> x >> y >> w >> h;
			int index = findWindow(x, y);
			if (index == -1)
				printf("Command %d: RESIZE - no window at given position\n", cnt);
			else {
				window a = windows[index];
				window an(a.l, a.l+w-1, a.b+h-1, a.b);
				bool room = true;
				for (int i = 0; i < (int)windows.size(); i++)
					if (i != index && intersect(windows[i], an))
						room = false;
				if (an.l < 0 || an.r >= xmax || an.b < 0 || an.t >= ymax)
					room = false;
				if (room)
					windows[index] = an;
				else
					printf("Command %d: RESIZE - window does not fit\n", cnt);
			}
		}
		else if (cmd == "MOVE") {
			int x, y, dx, dy; cin >> x >> y >> dx >> dy;
			int index = findWindow(x, y);
			if (index == -1)
				printf("Command %d: MOVE - no window at given position\n", cnt);
			else { // Rewrite this entire section if neccessary
				moved.clear();
				int off = 0;
				if (dx) {
					movex(index, dx);
					if (dx > 0) {
						for (ii move : moved)
							off = max(off, windows[move.first].r);
						off -= xmax-1;
						if (off > 0) {
							for (ii move : moved) {
								window& a = windows[move.first];
								int correction = min(move.second, off);
								a.l -= correction;
								a.r -= correction;
							}
						}
					}
					else if (dx < 0) {
						for (ii move : moved)
							off = min(off, windows[move.first].l);
						if (off < 0) {
							for (ii move : moved) {
								window& a = windows[move.first];
								int correction = max(move.second, off);
								a.l -= correction;
								a.r -= correction;
							}
						}
						off = -off;
					}
				}
				else if (dy) {
					movey(index, dy);
					if (dy > 0) {
						for (ii move : moved)
							off = max(off, windows[move.first].t);
						off -= ymax-1;
						if (off > 0) {
							for (ii move : moved) {
								window& a = windows[move.first];
								int correction = min(move.second, off);
								a.t -= correction;
								a.b -= correction;
							}
						}
					}
					else if (dy < 0) {
						for (ii move : moved)
							off = min(off, windows[move.first].b);
						if (off < 0) {
							for (ii move : moved) {
								window& a = windows[move.first];
								int correction = max(move.second, off);
								a.t -= correction;
								a.b -= correction;
							}
						}
						off = -off;
					}
				}
				int mv = abs(dx+dy);
				if (off > 0)
					printf("Command %d: MOVE - moved %d instead of %d\n", cnt, mv-off, mv);
			}
		}
		else
			throw cmd;
	}
	printf("%d window(s):\n", (int)windows.size());
	for (window a : windows)
		printf("%d %d %d %d\n", a.l, a.b, a.r-a.l+1, a.t-a.b+1);
}
