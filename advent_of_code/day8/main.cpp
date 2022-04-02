#include <bits/stdc++.h>
using namespace std;

bool isSubset(string a, string b) {
	bool res = true;
	for (char c : a)
		res &= b.find(c) != string::npos;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int result = 0;
	while (cin >> s) {
		vector<string> nums(10, "");
		vector<string> five, six;
		while (s != "|") {
			if (s.size() == 2l)
				nums[1] = s;
			else if (s.size() == 3l)
				nums[7] = s;
			else if (s.size() == 4l)
				nums[4] = s;
			else if (s.size() == 7l)
				nums[8] = s;
			else if (s.size() == 5l)
				five.push_back(s);
			else if (s.size() == 6l)
				six.push_back(s);
			else throw s;
			cin >> s;
		}
		for (string num : six) {
			if (isSubset(nums[4], num))
				nums[9] = num;
			else if (isSubset(nums[1], num))
				nums[0] = num;
			else
				nums[6] = num;
		}
		for (string num : five) {
			if (isSubset(nums[1], num))
				nums[3] = num;
			else if (isSubset(num, nums[6]))
				nums[5] = num;
			else
				nums[2] = num;
		}
		int part = 0;
		for (int i = 3; i >= 0; i--) {
			cin >> s;
			int k;
			for (k = 0; k < 10; k++)
				if (s.size() == nums[k].size() && isSubset(s, nums[k]))
					break;
			assert(k < 10);
			for (int j = 0; j < i; j++)
				k *= 10;
			part += k;
		}
		result += part;
		printf("part: %d\n", part);
	}
	printf("%d\n", result);
}
