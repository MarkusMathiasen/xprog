#include <bits/stdc++.h>
using namespace std;

string conv(int a, int b) {
	int num = 10*max(a, b) + min(a, b);
	if (num == 11)
		return "Pair 1";
	if (num == 22)
		return "Pair 2";
	if (num == 33)
		return "Pair 3";
	if (num == 44)
		return "Pair 4";
	if (num == 55)
		return "Pair 5";
	if (num == 66)
		return "Pair 6";
	if (num == 21)
		return "Majer";
	if (num == 31)
		return "Lille majer";
	if (num == 32)
		return "Faelles skaal";
	return to_string(num);
}

int main() {
	
	printf("%s\n", conv(a, b).c_str());
}
