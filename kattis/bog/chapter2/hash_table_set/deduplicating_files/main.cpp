#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n, n) {
		set<string> files;
		map<int, int> hashCount;
		map<string, int> fileCount;
		map<string, int> hashes;
		string s; getline(cin, s);
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			int hash = 0;
			for (char c : s)
				hash ^= c;
			hashes[s] = hash;
			hashCount[hash]++;
			fileCount[s]++;
			files.insert(s);
		}
		int cols = 0;
		for (auto& file : files)
			cols += fileCount[file] * (hashCount[hashes[file]]-fileCount[file]);
		cols /= 2;
		printf("%d %d\n", (int)files.size(), cols);
	}
}
