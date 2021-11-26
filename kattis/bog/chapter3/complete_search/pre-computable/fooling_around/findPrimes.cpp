#include <bits/stdc++.h>
using namespace std;

int N = 1e9;

bitset<1000000001> isNotPrime;

int main() {
	isNotPrime.set(0);
	isNotPrime.set(1);
	for (int i = 2; i <= ceil(sqrt(N)); i++)
		if (!isNotPrime[i])
			for (int j = i*i; j <= N; j += i)
				isNotPrime.set(j);
	for (int i = 0; i <= N; i++)
		if (!isNotPrime[i])
			printf("%d\n", i);

}
int N = 1e9+1;

vector<bool> isPrime(N, true);
vector<int> primesMinusOne;

int main() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= ceil(sqrt(N)); i++)
		if (isPrime[i])
			for (int j = i*i; j <= N; j += i)
				isPrime[j] = false;
	for (int i = 0; i <= N; i++)
		if (isPrime[i])
			primesMinusOne.push_back(i-1);
	for (int& x : primesMinusOne)
		printf("%d\n", x);
}
