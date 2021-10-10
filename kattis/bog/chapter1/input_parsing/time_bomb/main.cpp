#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> m = {
	"**** ** ** ****",
	"  *  *  *  *  *",
	"***  *****  ***",
	"***  ****  ****",
	"* ** ****  *  *",
	"****  ***  ****",
	"****  **** ****",
	"***  *  *  *  *",
	"**** ***** ****",
	"**** ****  ****"
};
vector<string> nums(10, "");

ll tonum(string s) {
	for (ll i = 0; i < 10; i++)
		if (m[i] == s)
			return i;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (ll i = 0; i < 5; i++) {
		string line; getline(cin, line);
		for (ll d = 0; d*4 < (ll)line.size(); d++)
			nums[d] += line.substr(d*4, 3);
	}
	while (nums.back() == "")
		nums.pop_back();
	ll res = 0;
	bool pos = true;
	for (ll i = 0; i < (ll) nums.size(); i++) {
		res *= 10;
		ll x = tonum(nums[i]);
		if (x < 0)
			pos = false;
		res += tonum(nums[i]);
	}
	printf(res%6 || !pos ? "BOOM!!\n" : "BEER!!\n");
}
