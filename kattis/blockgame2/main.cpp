#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, m;

bool canWin(ll a, ll b){
	if (a >= 2*b) return true;
	if (a == b) return true;
	return !canWin(b, a-b);
}

int main(){
	scanf("%lld %lld", &n, &m);
	if (canWin(max(n, m), min(n, m)))
		printf("win\n");
	else
		printf("lose\n");
}
