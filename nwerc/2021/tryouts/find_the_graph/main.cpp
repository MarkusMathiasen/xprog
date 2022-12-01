#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> deg(n);
	for (int i = 0; i < n; i++) {
		cout << "? 1 " << i+1 << endl;
		cin >> deg[i];
	}
	vector<vector<int>> mat(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++) {
			cout << "? 2 " << i+1 << " " << j+1 << endl;
			int x; cin >> x;
			if (x != deg[i] + deg[j])
				mat[i][j] = mat[j][i] = 1;
		}
	cout << "!" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}
