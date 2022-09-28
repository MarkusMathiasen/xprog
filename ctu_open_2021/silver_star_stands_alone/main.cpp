#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> primes = {2};
	for (int i = 3; i < 250; i++) {
		bool isPrime = true;
		for (int p : primes)
			isPrime &= i%p > 0;
		if (isPrime)
			primes.push_back(i);
	}
	vector<long long> traj(300, 0);
	traj[2] = 1;
	for (int p : primes)
		for (int i = 1; i <= 14; i++)
			traj[p+i] += traj[p];
	int x; scanf("%d", &x);
	printf("%lld\n", traj[x]);
}
