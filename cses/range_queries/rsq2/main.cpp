#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, q;
ll ft[400001];

int lsb(int i) {return i&(-i);}
void update(int i, int k){
	for (i; i <= n; i += lsb(i))
		ft[i] += k;
}
ll sum(int i){
	ll result = 0;
	for (i; i > 0; i -= lsb(i))
		result += ft[i];
	return result;
}
ll rsq(int a, int b){return sum(b)-sum(a-1);}
void change(int i, int u){
	ll val = rsq(i, i);
	ll k = u-val;
	update(i, k);
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++){
		int c; scanf("%d", &c);
		update(i, c);
	}
	while (q--){
		int o, a, b; scanf("%d %d %d", &o, &a, &b);
		if (o == 1)
			change(a, b);
		if (o == 2)
			printf("%lld\n", rsq(a, b));
	}
}
