#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string N, M; cin >> N >> M;
	int m = M.size()-1;
	vector<char> A(m, '0');
	for (char c : N)
		A.push_back(c);
	A.insert(A.end()-m, '.');
	while (A.back() == '0')
		A.pop_back();
	int start = 0;
	while (A[start] == '0' && A[start+1] != '.')
		start++;
	if (A.back() == '.')
		A.pop_back();
	for (int i = start; i < (int)A.size(); i++)
		printf("%c", A[i]);
	printf("\n");
}
