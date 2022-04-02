#include <bits/stdc++.h>
using namespace std;

int length = 12;
vector<int> cnt(length, 0);
int n = 0;
vector<string> nums;

int findNum(function<bool(const int a, const int b)> comp) {
	int n1 = n;
	vector<int> cnt1 = cnt;
	vector<bool> chosen(n, true);
	int pos = 0;
	while (n1 > 1) {
		char discard = comp(cnt1[pos]*2, n1) ? '1' : '0';
		for (int i = 0; i < n; i++)
			if (chosen[i] && nums[i][pos] == discard) {
				chosen[i] = false;
				n1--;
				for (int j = 0; j < length; j++)
					cnt1[j] -= nums[i][j] == '1';
			}
		pos++;
	}
	int res = -1;
	for (int i = 0; i < n; i++)
		if (chosen[i]) {
			res = 0;
			for (int j = 0; j < length; j++)
				if (nums[i][length-1-j] == '1')
					res += 1<<j;
		}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s) {
		n++;
		nums.push_back(s);
		for (int i = 0; i < length; i++)
			cnt[i] += s[i] == '1';
	}
	int oxygen = findNum([](const int a, const int b) {return a < b;});
	int co2 = findNum([](const int a, const int b) {return a >= b;});
	printf("co2: %d\n", co2);
	printf("oxygen: %d\n", oxygen);
	printf("%d\n", co2*oxygen);
}
