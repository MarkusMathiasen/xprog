#include <bits/stdc++.h>
using namespace std;

int T;
int ng, nm;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &ng, &nm);
		int godMax = 0;
		int mekMax = 0;
		for (int i = 0; i < ng; i++) {
			int x; scanf("%d", &x); godMax = max(godMax, x);
		}
		for (int i = 0; i < nm; i++) {
			int x; scanf("%d", &x); mekMax = max(mekMax, x);
		}
		printf(godMax >= mekMax ? "Godzilla\n" : "MechaGodzilla\n");
	}
}
