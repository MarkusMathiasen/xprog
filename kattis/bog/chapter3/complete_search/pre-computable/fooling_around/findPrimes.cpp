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
