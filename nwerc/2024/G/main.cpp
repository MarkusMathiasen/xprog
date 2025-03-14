#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	double cross(P p) const { return (double)x*(double)p.y - (double)y*(double)p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

ll n;
vector<Point<ll>> pts, pre, suf;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n;
	pts.resize(n);
	rep(i, 0, n) cin >> pts[i].x >> pts[i].y;
	double area = 0;
	rep(i, 0, n) {
		area += pts[i].cross(pts[(i+1)%n]);
	}
	pre.resize(n);
	pre[0] = pts[0];
	rep(i, 0, n-1) {
		pre[i+1] = pre[i] + pts[i];
	}
	suf.resize(n);
	suf[n-1] = pts[n-1];
	for (ll i = n-2; i >= 0; i--) {
		suf[i] = suf[i+1] + pts[i];
	}
	double area2 = 0;
	rep(j, 1, n-1) {
		double inc = (pts[j]*j - pre[j-1]).cross(suf[j+1]-pts[j]*(n-j-1));
		assert(inc >= 0);
		area2 += inc;
	}
	double res = area2/(double)area;
	printf("%.8f\n", res);
}
