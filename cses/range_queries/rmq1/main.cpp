#include <bits/stdc++.h>

using namespace std;

int n, q;
int st[800000];
int p[200000];

int left(int i) {return i*2;}
int right(int i) {return i*2+1;}
void build(int i, int L, int R){
	if (L == R)
		{scanf("%d", &st[i]); return;}
	int mid = (L+R)/2;
	build(left(i), L, mid);
	build(right(i), mid+1, R);
	st[i] = min(st[left(i)], st[right(i)]);
}

int rmqA(int i, int l, int r, int L, int R){
	if (L > r || R < l) return INT_MAX;
	if (L >= l && R <= r) return st[i];
	int mid = (L+R)/2;
	int goL = rmqA(left(i), l, r, L, mid);
	int goR = rmqA(right(i), l, r, mid+1, R);
	return min(goL, goR);
}

int rmq(int l, int r) {return rmqA(1, l, r, 1, n);}

int main(){
	scanf("%d %d", &n, &q);
	build(1, 1, n);
	while (q--){
		int a, b; scanf("%d %d", &a, &b);
		printf("%d\n", rmq(a, b));
	}
}
