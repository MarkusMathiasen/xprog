#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> res;
	for (int i = 1; i <= 5; i++) {
		string s; getline(cin, s);
		bool found = false;
		for (int j = 0; j <= (int)s.size()-3; j++) {
			found |= s.substr(j, 3) == "FBI";
		}
		if (found)
			res.push_back(i);
	}
	if (!res.size())
		printf("HE GOT AWAY!\n");
	else {
		for (int x : res)
			printf("%d ", x);
		printf("\n");
	}
}
