#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string A, B; cin >> A >> B;
	int a, b; a = b = -1;
	for (a = 0; a < (int)A.size(); a++) {
		if (B.find(A[a]) != string::npos) {
			b = B.find(A[a]);
			break;
		}
	}
	if (b == -1)
		throw b;
	for (int row = 0; row < (int)B.size(); row++) {
		if (row == b)
			printf("%s\n", A.c_str());
		else {
			for (int i = 0; i < a; i++)
				printf(".");
			printf("%c", B[row]);
			for (int i = a+1; i < (int)A.size(); i++)
				printf(".");
			printf("\n");
		}
	}
}
