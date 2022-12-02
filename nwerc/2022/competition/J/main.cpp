#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef vector<int> vi;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); }
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int n, cnt=0;
set<int> s;
unordered_map<int, int> m;
vector<vi> A;

int main() {
	scanf("%d", &n);
	A.assign(n, vi(3, 0));
	rep(i, 0, n)
		scanf("%d%d", &A[i][0], &A[i][1]),
		A[i][1] += A[i][0],
		s.insert(A[i][0]),
		s.insert(A[i][1]),
		A[i][2] = i;
	for (int x : s)
		m[x] = cnt++;
	for (vi& a : A)
		a[0] = m[a[0]],
		a[1] = m[a[1]];
	sort(all(A), [](const vi& a, const vi& b){
		if (a[0] != b[0])
			return a[0] < b[0];
		return a[1] > b[1];
	});
	Tree st(cnt, 0);
	vi res(n, 0);
	for (vi& a : A) {
		res[a[2]] = st.query(a[1], cnt);
		st.update(a[1], res[a[2]]+1);
	}
	for (int x : res)
		printf("%d ", x);
	printf("\n");
}
