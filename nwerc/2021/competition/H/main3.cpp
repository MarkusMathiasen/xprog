#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct li {
	ll inc;
	ll req;
	li* next = nullptr;
	li* prev = nullptr;
	li(ll startv) : inc(startv), req(startv) {}
};
int n;
vector<ll> slices;
vector<li> lis;
vector<li> lis2;

void initLi() {
	lis2 = lis;
	for (int i = 0; i < n-1; i++)
		lis2[i].next = &lis2[i+1];
	lis2[n-1].next = &lis2[0];
	for (int i = 1; i < n; i++)
		lis2[i].prev = &lis2[i-1];
	lis2[0].prev = &lis2[n-1];
}

void rem(li* x) {
	(x->prev)->next = x->next;
	(x->next)->prev = x->prev;
	x->req = -1;
}

bool possible(ll level) {
	initLi();
	for (int i = 0; i < n; i++) {
		if (lis2[i].req < 0)
			continue;
		if (lis2[i].req <= level) {
			while (&lis2[i] != lis2[i].next) {
				if (lis2[i].prev->req <= level+lis2[i].inc) {
					lis2[i].inc += lis2[i].prev->inc;
					lis2[i].req = min(lis2[i].req, lis2[i].prev->req);
					rem(lis2[i].prev);
				}
				else if (lis2[i].next->req <= level+lis2[i].inc) {
					lis2[i].inc += lis2[i].next->inc;
					lis2[i].req = min(lis2[i].req, lis2[i].next->req);
					rem(lis2[i].next);
				}
				else
					break;
			}
			if (&lis2[i] == lis2[i].next)
				return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	slices.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &slices[i]),
		lis.push_back(li(slices[i]));
	ll low = 0;
	ll high = 1e14;
	while (low < high) {
		ll mid = (low+high)/2;
		if (possible(mid))
			high = mid;
		else
			low = mid+1;
	}
	printf("%lld\n", low);
}
