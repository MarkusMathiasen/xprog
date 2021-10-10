#include <bits/stdc++.h>

using namespace std;
#define ll long long

int a, b, c;
vector<int> right3, left1, input;
int n;

int main() {
	cin >> n;
	if (n < 3) {
		cout << 0 << endl;
		return 0;
	}
	input.assign(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		if (input[i] == 2)
			b++;
	}
	right3.assign(b, 0);
	left1.assign(b, 0);
	int twoCount = 0;
	for (int i = 0; i < n; i++) {
		if (input[i] == 1)
			a++;
		if (input[i] == 2) {
			left1[twoCount] = a;
			twoCount++;
		}
	}
	twoCount--;
	for (int i = n-1; i >= 0; i--) {
		if (input[i] == 3)
			c++;
		if (input[i] == 2) {
			right3[twoCount] = c;
			twoCount--;
		}
	}
	if (b == 0) {
		cout << 0 << endl;
		return 0;
	}
	vector<ll> dp(b, 0);
	dp[b-1] = right3[b-1];
	for (int i = b-2; i >= 0; i--) {
		dp[i] = 2*dp[i+1]-right3[i+1]+right3[i] % 1000000007;
	}
	long long res = 0;
	for (int i = 0; i < b; i++) {
		res += left1[i] * dp[i];
		res %= 1000000007;
	}
	cout << res << endl;
	
}
