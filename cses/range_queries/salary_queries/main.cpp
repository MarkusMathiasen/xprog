#include <bits/stdc++.h>

using namespace std;

int n, q;
int ft[1000001];
int p[200001];

void update(int i, int k){
	while (i <= n)
		ft[i] += k, i += i&(-i);
}
int rsq(int i){
	int result = 0;
	while (i > 0)
		result += ft[i], i -= i&(-i);
	return result;
}
int get(int i) {return rsq(i)-rsq(i-1);}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++){
		int c; scanf("%d", &c);
		update(c, 1);
		p[i] = c;
	}
	while (q--){
		char c; int a, b; scanf(" %c %d %d", &c, &a, &b);
		if (c == '?')
			printf("%d\n", rsq(b)-rsq(a-1));
		else{
			update(p[a], -1);
			update(b, 1);
			p[a] = b;
		}
	}
	return 0;
}
