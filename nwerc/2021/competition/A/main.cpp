#include <bits/stdc++.h>
using namespace std;

int timAns;

bool guess(string& s) {
	cout << s << endl;
	string ans; cin >> ans >> ans;
	if (ans == "GRANTED")
		return true;
	cin >> ans;
	timAns = stoi(ans.substr(1, ans.size()-1));
	cin >> ans;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len;
	string x = "A";
	for (len = 1; true; len++) {
		if (guess(x)) {
			return 0;
		}
		if (timAns > 5)
			break;
		x.push_back('A');
	}
	for (int i = 0; i < len; i++) {
		while (timAns <= 14 + i*9) {
			if (x[i] == 'Z')
				x[i] = 'a';
			else if (x[i] == 'z')
				x[i] = '0';
			else if (x[i] == '9')
				assert(false);
			else
				x[i]++;
			if (guess(x))
				return 0;
		}
	}
}
