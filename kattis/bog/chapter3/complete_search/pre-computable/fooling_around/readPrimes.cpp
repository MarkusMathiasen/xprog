#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int amount = 50847534;
ll start, finish;
vector<int> primes;

int main() {
	start = time(nullptr);
	FILE* p = fopen("primes.txt", "r");
	for (int pos = 0; pos < amount; pos++) {
		int x;
		fscanf(p, "%d", &x);
		primes.push_back(x);
	}
	finish = time(nullptr);
	printf("%lld\n", finish-start);
	printf("lastElement: %lld\n", primes[amount-1]);
	printf("size: %ld\n", primes.size());
}
