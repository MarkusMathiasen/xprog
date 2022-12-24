#include <bits/stdc++.h>
using namespace std;

string dic = "";
vector<string> img(0, "");
bool flipped = false;

char conv(int x, int y) {
	int idx = 0;
	int cnt = 9;
	for (int i = x-1; i <= x+1; i++)
		for (int j = y-1; j <= y+1; j++) {
			cnt--;
			if (0 <= i && i < (int)img.size() && 0 <= j && j < (int)img[0].size()) {
				if (img[i][j] == '#')
					idx |= 1<<cnt;
			} else if (flipped)
				idx |= 1<<cnt;
		}
	return dic[idx];
}

void printImg(vector<string>& s) {
	for (string& a : s)
		cout << a << endl;
	cout << endl;
}

int count(vector<string>& s) {
	int res = 0;
	for (string& a : s)
		for (char c : a)
			res += c == '#';
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> dic;
	string s;
	while (cin >> s)
		img.push_back(s);
	for (int k = 0; k < 50; k++) {
		vector<string> img2(0, "");
		for (int i = -1; i <= (int)img.size(); i++) {
			img2.push_back("");
			for (int j = -1; j <= (int)img[0].size(); j++)
				img2.back().push_back(conv(i, j));
		}
		if (!flipped && dic[0] == '#')
			flipped = true;
		else if (flipped && dic[511] == '.')
			flipped = false;
		img = img2;
	}
	printf("%d\n", count(img));
}
