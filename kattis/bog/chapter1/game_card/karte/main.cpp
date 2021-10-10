#include <bits/stdc++.h>
using namespace std;

set<string> P, K, H, T;

int main() {
	char c1, c2, c3;
	bool fail = false;
	while (scanf("%c%c%c", &c1, &c2, &c3) != EOF) {
		string s(1, c2);
		s.push_back(c3);
		if (c1 == 'P') {
			if (P.count(s))
				fail = true;
			P.insert(s);
		}
		if (c1 == 'K') {
			if (K.count(s))
				fail = true;
			K.insert(s);
		}
		if (c1 == 'H') {
			if (H.count(s))
				fail = true;
			H.insert(s);
			
		}
		if (c1 == 'T') {
			if (T.count(s))
				fail = true;
			T.insert(s);
		}
	}
	if (fail) {
		printf("GRESKA\n");
		return 0;
	}
	printf("%d %d %d %d\n", 13-(int)P.size(), 13-(int)K.size(), 13-(int)H.size(), 13-(int)T.size());
}
