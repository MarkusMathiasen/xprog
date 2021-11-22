#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int>& A) {
	queue<int> Q;
	for (int x : A)
		Q.push(x);
	vector<int> res;
	for (int i = 0; i < (int)A.size(); i++) {
		for (int j = 0; j <= i; j++)
			Q.push(Q.front()), Q.pop();
		res.push_back(Q.front());
		Q.pop();
		if (res.size() > 1l && res.back() > res[res.size()-2])
			return false;
	}
	return true;
}

int main() {
	for (int i = 1; i <= 13; i++) {
		vector<int> A;
		for (int j = 1; j <= i; j++)
			A.push_back(j);
		do {
			if (valid(A)) {
				for (int x : A)
					printf("%d ", x);
				printf("\n");
			}
		} while (next_permutation(A.begin(), A.end()));
	}
}
