#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> A = {
	"clank",
	"bong",
	"click",
	"tap",
	"poing",
	"clonk",
	"clack",
	"ping",
	"tip",
	"cloing",
	"tic",
	"cling",
	"bing",
	"pong",
	"clang",
	"pang",
	"clong",
	"tac",
	"boing",
	"boink",
	"cloink",
	"rattle",
	"clock",
	"toc",
	"clink",
	"tuc"
};
map<string, char> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 26; i++)
		m[A[i]] = 'a'+i;
	bool caps = false, shift = false;
	cin >> n;
	string res = "";
	while (n--) {
		string s; cin >> s;
		if (s == "pop") {
			if (res.size())
				res.pop_back();
		}
		else if (s == "bump")
			caps = !caps;
		else if (s == "whack")
			res.push_back(' ');
		else if (s == "dink")
			shift = true;
		else if (s == "thumb")
			shift = false;
		else {
			if (!m.count(s))
				return 0;
			if (shift ^ caps)
				res.push_back(toupper(m[s]));
			else
				res.push_back(m[s]);
		}
	}
	cout << res << endl;
}
