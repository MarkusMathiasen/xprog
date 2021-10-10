#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct window {
	ll number;
	ll l; // left
	ll r; // right
	ll t; // top
	ll b; // bottom
	window(ll l, ll r, ll t, ll b, ll number) {
		this->l = l;
		this->r = r;
		this->t = t;
		this->b = b;
		this->number = number;
	}
};

ll xmax, ymax;
vector<window> windows;
map<ll, ll> moved;

bool intersect(window& a, window& b) {
	return a.t >= b.b && a.b <= b.t && a.r >= b.l && a.l <= b.r;
}
bool intersect(window& a, ll x, ll y) {
	return a.l <= x && a.r >= x && a.t >= y && a.b <= y;
}
ll findWindow(ll x, ll y) {
	for (ll i = 0; i < (ll)windows.size(); i++)
		if (intersect(windows[i], x, y))
			return i;
	return -1;
}

void movex(ll index, ll dx) {
	if (moved.count(index))
		return;
	if (index >= (ll)windows.size() || index < 0)
		return;
	window& a = windows[index];
	vector<ll> movers;
	if (dx > 0) {
		window box(a.r+1, a.r+dx, a.t, a.b, -1);
		for (ll i = 0; i < (ll)windows.size(); i++)
			if (intersect(box, windows[i]))
				movers.push_back(i);
		sort(movers.begin(), movers.end(), [](ll a, ll b) {
			return windows[a].l <= windows[b].l;
		});
		for (ll mover : movers) {
			if (intersect(box, windows[mover]))
				movex(mover, box.r-windows[mover].l+1);
		}
	}
	else if (dx < 0) {
		window box(a.l+dx, a.l-1, a.t, a.b, -1);
		for (ll i = 0; i < (ll) windows.size(); i++)
			if (intersect(box, windows[i]))
				movers.push_back(i);
		sort(movers.begin(), movers.end(), [](ll a, ll b) {
			return windows[a].r >= windows[b].r;
		});
		for (ll mover : movers) {
			if (intersect(box, windows[mover]))
				movex(mover, box.l - windows[mover].r-1);
		}
	}
	a.l += dx;
	a.r += dx;
	moved[index] = dx;
}

void movey(ll index, ll dy) {
	if (moved.count(index))
		return;
	if (index >= (ll)windows.size() || index < 0)
		return;
	window& a = windows[index];
	vector<ll> movers;
	if (dy > 0) {
		window box(a.l, a.r, a.t+dy, a.t+1, -1);
		for (ll i = 0; i < (ll)windows.size(); i++) {
			if (intersect(box, windows[i]))
				movers.push_back(i);
		}
		sort(movers.begin(), movers.end(), [](ll a, ll b) {
			return windows[a].b <= windows[b].b;
		});
		for (ll mover : movers)
			if (intersect(box, windows[mover]))
				movey(mover, box.t-windows[mover].b+1);
	}
	else if (dy < 0) {
		window box(a.l, a.r, a.b-1, a.b+dy, -1);
		for (ll i = 0; i < (ll)windows.size(); i++)
			if (intersect(box, windows[i]))
				movers.push_back(i);
		sort(movers.begin(), movers.end(), [](ll a, ll b) {
			return windows[a].t >= windows[b].t;
		});
		for (ll mover : movers) {
			if (intersect(box, windows[mover]))
				movey(mover, box.b - windows[mover].t-1);
		}
	}
	a.t += dy;
	a.b += dy;
	moved[index] = dy;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> xmax >> ymax;
	string cmd; ll cnt = 0;
	while (cin >> cmd) {
		cnt++;
		if (cmd == "OPEN") {
			ll x, y, w, h; cin >> x >> y >> w >> h;
			window a(x, x+w-1, y+h-1, y, cnt);
			bool space = true;
			for (window wind : windows)
				if (intersect(a, wind))
					space = false;
			if (space)
				windows.push_back(a);
			else
				printf("Command %lld: OPEN - window does not fit\n", cnt);
		}
		else if (cmd == "CLOSE") {
			ll x, y; cin >> x >> y;
			ll index = findWindow(x, y);
			if (index == -1)
				printf("Command %lld: CLOSE - no window at given position\n", cnt);
			else if (index >= (ll)windows.size() || index < 0)
				return 0;
			else
				windows.erase(windows.begin()+index);
		}
		else if (cmd == "RESIZE") {
			ll x, y, w, h; cin >> x >> y >> w >> h;
			ll index = findWindow(x, y);
			if (index == -1)
				printf("Command %lld: RESIZE - no window at given position\n", cnt);
			else {
				if (index < 0 || index >= (ll)windows.size())
					return 0;
				window& a = windows[index];
				window na(a.l, a.l+w-1, a.b+h-1, a.b, a.number);
				bool space = true;
				for (ll i = 0; i < (ll)windows.size(); i++) {
					if (i == index)
						continue;
					if (intersect(na, windows[i]))
						space = false;
				}
				if (space)
					windows[index] = na;
				else
					printf("Command %lld: RESIZE - window does not fit\n", cnt);
			}
		}
		else if (cmd == "MOVE") {
			ll x, y, dx, dy; cin >> x >> y >> dx >> dy;
			ll index = findWindow(x, y);
			if (index == -1)
				printf("Command %lld: MOVE - no window at given position\n", cnt);
			else {
				moved.clear();
				ll rat = 0;
				if (dx) {
					movex(index, dx);
					ll over = 0;
					ll under = 0;
					for (auto move : moved) {
						over = max(over, windows[move.first].r - (xmax-1));
						under = min(under, windows[move.first].l);
					}
					rat = -over-under;
					for (auto move : moved) {
						windows[move.first].l += rat;// > 0 ? min(rat, -move.second) : max(rat, -move.second);
						windows[move.first].r += rat;// > 0 ? min(rat, -move.second) : max(rat, -move.second);
					}
				}
				if (dy) {
					movey(index, dy);
					ll over = 0, under = 0;
					for (auto move : moved) {
						over = max(over, windows[move.first].t - (ymax-1));
						under = min(under, windows[move.first].b);
					}
					rat = -over-under;
					for (auto move : moved) {
						windows[move.first].t += rat > 0 ? min(rat, -move.second) : max(rat, -move.second);
						windows[move.first].b += rat > 0 ? min(rat, -move.second) : max(rat, -move.second);
					}
				}
				if (rat != 0)
					printf("Command %lld: MOVE - moved %lld instead of %lld\n", cnt, abs(dx+dy+rat), abs(dx+dy));
			}
		}
		else
			return 0;
			//throw cmd;
	}
	printf("%lld window(s):\n", (ll)windows.size());
	sort(windows.begin(), windows.end(), [](window a, window b) {
		return a.number <= b.number;
	});
	for (window a : windows)
		printf("%lld %lld %lld %lld\n", a.l, a.b, a.r-a.l+1, a.t-a.b+1);
}
