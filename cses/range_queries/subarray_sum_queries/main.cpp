#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct node{
	int L;
	int R;
	ll presum;
	ll subsum;
	ll sum;
	ll maxsum;
};

node st[800001];
int n, m;

int l(int i) {return i*2;}
int r(int i) {return i*2+1;}

void build(int p, int L, int R){
	st[p].L = L;
	st[p].R = R;
	if (L == R){
		scanf("%lld", &st[p].maxsum);
		st[p].presum = st[p].subsum = st[p].sum = st[p].maxsum;
		return;
	}
	int mid = (L + R)/2;
	build(l(p), L, mid);
	build(r(p), mid+1, R);

	st[p].sum = st[l(p)].sum+st[r(p)].sum;
	st[p].presum = max(st[l(p)].presum, st[l(p)].sum + st[r(p)].presum);
	st[p].subsum = max(st[r(p)].subsum, st[r(p)].sum + st[l(p)].subsum);
	st[p].maxsum = max(st[l(p)].subsum+st[r(p)].presum, 
			max(max(st[p].presum, st[p].subsum), 
				max(st[l(p)].maxsum, st[r(p)].maxsum)));
}
void change(int p, int t, int v){
	if (st[p].L > t || st[p].R < t) return;
	if (st[p].L == t && st[p].R == t){
		st[p].presum = st[p].subsum = st[p].maxsum = st[p].sum = v;
		return;
	}
	change(l(p), t, v);
	change(r(p), t, v);

	st[p].sum = st[l(p)].sum+st[r(p)].sum;
	st[p].presum = max(st[l(p)].presum, st[l(p)].sum + st[r(p)].presum);
	st[p].subsum = max(st[r(p)].subsum, st[r(p)].sum + st[l(p)].subsum);
	st[p].maxsum = max(st[l(p)].subsum+st[r(p)].presum, 
			max(max(st[p].presum, st[p].subsum), 
				max(st[l(p)].maxsum, st[r(p)].maxsum)));
}

int main(){
	scanf("%d %d", &n, &m);
	build(1, 1, n);
	while (m--){
		int t, v; scanf("%d %d", &t, &v);
		change(1, t, v);
		printf("%lld\n", max(st[1].maxsum, (ll)0));
	}
}
