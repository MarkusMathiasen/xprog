#include <bits/stdc++.h>

using namespace std;

int n;
int p[200001], ft[200001];

int lsb(int i){return i&(-i);}
void update(int i, int k){
	while (i <= n)
		ft[i] += k, i += lsb(i);
}
int rsq(int i){
	int result = 0;
	while (i > 0)
		result += ft[i], i -= lsb(i);
	return result;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]), update(i, 1);
	for (int i = 0; i < n; i++){
		int pos; scanf("%d", &pos);
		int upper = n;
		int lower = 1;
		while (upper != lower){
			int mid = (upper+lower)/2;
			int sum = rsq(mid);
			if (sum >= pos) upper = mid;
			else lower = mid+1;
		}
		printf("%d ", p[lower]);
		update(lower, -1);
	}
}
