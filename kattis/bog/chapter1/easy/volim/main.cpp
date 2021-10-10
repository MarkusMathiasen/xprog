#include <bits/stdc++.h>
using namespace std;

int K, N, t = 0;

int main() {
	cin >> K >> N;
	int res = 0;
	for (int i = 0; i < N; i++) {
		int w; cin >> w; t += w;
		char c; cin >> c;
		if (t > 3*60+30)
			break;
		if (c == 'T')
			res++;
	}
	cout << ((res+K-1)%8)+1 << endl;
}
