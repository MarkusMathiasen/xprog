#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b; scanf("%d%d", &a, &b);
	int an; scanf("%d", &an);
	vector<int> A(an, 0);
	for (int i = 0; i < an; i++)
		scanf("%d", &A[i]);
	int bn; scanf("%d", &bn);
	vector<int> B(bn, 0);
	for (int i = 0; i < bn; i++)
		scanf("%d", &B[i]);
	if (a < b)
		a += 4;
	else
		b += 4;
	int ia = 0, ib = 0;
	bool da = false, db = false;
	int res = -1;
	for (int t = 1; t <= (int)4e6; t++) {
		a += da, b += db;
		if (ia < an && A[ia] == t)
			ia++, da = !da;
		if (ib < bn && B[ib] == t)
			ib++, db = !db;
		if (a == b) {
			res = t;
			break;
		}
	}
	if (res == -1)
		printf("safe and sound\n");
	else
		printf("bumper tap at time %d\n", res);
}
