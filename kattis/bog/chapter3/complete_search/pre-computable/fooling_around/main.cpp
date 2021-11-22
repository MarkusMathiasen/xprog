#include <bits/stdc++.h>
using namespace std;

int N = 1e9+1;

vector<bool> isPrime(N, true);
vector<int> primesMinusOne;
vector<bool> losing(N, true);

int main() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= ceil(sqrt(N)); i++)
		if (isPrime[i])
			for (int j = i*i; j <= N; j += i)
				isPrime[j] = false;
	for (int i = 0; i <= N; i++)
		if (isPrime[i])
			primesMinusOne.push_back(i-1);
	printf("%ld\n", primesMinusOne.size());
	for (int i = 0; i <= N; i++) {
		if (losing[i]) {
			for (int x : primesMinusOne) {
				if (x+i > N)
					break;
				losing[x+i] = false;
			}
		}
	}
	printf("Bob wins:\n");
	int solutions = 0;
	for (int i = 0; i <= N; i++) {
		if (losing[i])
			printf("%d\n", i),
			solutions++;
	}
	printf("Number of solutions: %d\n", solutions);
}
