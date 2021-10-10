#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n != -1) {
		int graph[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> graph[i][j];
		for (int v = 0; v < n; v++) {
			bool found = false;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					found |= graph[v][i] & graph[v][j] & graph[j][i];
			if (!found)
				cout << v << " ";
		}
		cout << "\n";
		cin >> n;
	}
}
