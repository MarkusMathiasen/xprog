#include <bits/stdc++.h>
using namespace std;

int main() {
	string a; int k; cin >> a >> k;
	string b = a;
	sort(a.begin(), a.end());
	int left = a.size()/2;
	while (left < (int)a.size() && a[left] == b[left])
		left++;
	int right = a.size()/2-1;
	while (right && a[right] == b[right])
		right--;
	right = a.size()-1-right;
	printf(k <= min(left, right) ? "Yes\n" : "No\n");
}
