#include <bits/stdc++.h>
using namespace std;

int L, W;
vector<int> O, I, S;

void moveCars() {
	for (int i = 0; i < L; i++) {
		O[i] += S[i];
		while (O[i]-I[i] >= 0)
			O[i] -= I[i];
	}
}

bool isSafe(int w, int l) {
	if (l == L || l < 0)
		return true;
	int car = O[l];
	if (l%2 == 0) {
		while (car < w)
			car += I[l];
		if (car == w) // S[l] == 0 case
			return false;
		if (car - S[l] < w)
			return false;
	} else {
		car = W-1-car;
		while (car > w)
			car -= I[l];
		if (car == w) // S[l] == 0 case
			return false;
		if (car + S[l] > w)
			return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &L, &W);
	O.assign(L, 0);
	I.assign(L, 0);
	S.assign(L, 0);
	for (int i = 0; i < L; i++)
		scanf("%d%d%d", &O[i], &I[i], &S[i]);
	int w, l = L; scanf("%d", &w);
	char move;
	while (scanf(" %c", &move) != EOF) {
		moveCars();
		if (move == 'U')
			l--;
		else if (move == 'D') {
			if (l == L-1)
				throw move;
			l++;
		}
		else if (move == 'L')
			w--;
		else if (move == 'R')
			w++;
		else
			throw move;
		if (w < 0 || w >= W || l < -1 || l > L)
			throw move;
		if (!isSafe(w, l))
			break;
	}
	printf(l < 0 ? "safe\n" : "squish\n");
}
