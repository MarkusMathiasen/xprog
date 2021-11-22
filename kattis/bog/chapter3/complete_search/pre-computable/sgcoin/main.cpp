#include <bits/stdc++.h>
using namespace std;

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < (int)transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

long long findToken(long long previousHash, string &transaction) {
  long long v = previousHash;
  for (int i = 0; i < (int)transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  v = v*7%1000000007;
  if (v < 1000000000)
	  return 1000000000-v;
  return 1000000007-v + 1000000000;
}

int main() {
	string a = "a";
	string b = "b";
	long long prev; scanf("%lld", &prev);
	long long token = findToken(prev, a);
	assert(H(prev, a, token) % 10000000 == 0);
	assert(token < 1e9);
	printf("a %lld\n", token);
	prev = H(prev, a, token);
	token = findToken(prev, b);
	assert(H(prev, b, token) % 10000000 == 0);
	assert(token < 1e9);
	printf("b %lld\n", token);
}
