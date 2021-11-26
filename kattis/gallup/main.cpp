#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, sum;
vector<int> nums;
int T = 0;

ll rounds(ll sub, ll all, ll frac) {
	ll res = sub*sum / all;
	if (((sub*sum)%all)*2 >= all)
		res++;
	return res - frac;
}

bool valid(int amount, int i, int remaining) {
	if (i == n)
		return remaining == 0;
	if (remaining < 0)
		return false;
	int frac = nums[i];
	int low = 0;
	int high = remaining;
	while (low < high) {
		int mid = (low + high)/2;
		if (rounds(mid, amount, frac) < 0l)
			low = mid+1;
		else
			high = mid;
	}
	while (low <= remaining && rounds(low, amount, frac) == 0l) {
		if (valid(amount, i+1, remaining-low))
			return true;
		low++;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n, n) {
		nums.assign(n, 0);
		sum = 0;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			stringstream ss(s);
			string a; string b;
			getline(ss, a, '.');
			getline(ss, b);
			int num = stoi(a);
			sum = 100;
			for (int j = 0; j < (int)b.size(); j++)
				num *= 10, sum *= 10;
			if (b.size())
				num += stoi(b);
			nums[i] = num;
		}
		int res;
		for (res = 1; res < 10000; res++)
			if (valid(res, 0, res))
				break;
		printf("Case %d: ", ++T);
		if (res == 10000)
			printf("error\n");
		else
			printf("%d\n", res);
	}
}
