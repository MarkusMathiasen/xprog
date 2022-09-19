#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> si;

int main() {
	int N; scanf("%d", &N);
	vector<si> A(N, si());
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
		if (A[i].first == "cylinder")
			A[i].second *= 2;
	}
	sort(A.begin(), A.end(), [](const si& a, const si& b) {
		if (a.second != b.second)
			return a.second < b.second;
		return a.first != "cube";
	});
	for (int i = 0; i < N; i++)
		if (A[i].first == "cylinder")
			A[i].second /= 2;
	bool possible = true;
	for (int i = 1; i < N; i++)
		if (A[i-1].first == "cube" && A[i].first == "cylinder" &&
			A[i-1].second*A[i-1].second > A[i].second*A[i].second*2)
			possible = false;
	if (possible) {
		for (si& x : A)
			printf("%s %d\n", x.first.c_str(), x.second);
	}
	else
		printf("impossible\n");
}
