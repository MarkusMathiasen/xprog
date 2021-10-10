#include <bits/stdc++.h>
using namespace std;

vector<int> reg(10, 0), ram(1000, 0);

int main() {
	for (int i = 0; i < 1000; i++)
		if (scanf("%d", &ram[i]) == EOF)
			break;
	int pos = 0, res = 0;
	while (++res) {
		int a = ram[pos]/100;
		int b = (ram[pos]%100)/10;
		int c = ram[pos]%10;
		if (a == 1) {
			break;
		} else if (a == 2) {
			reg[b] = c;
		} else if (a == 3) {
			reg[b] = (reg[b]+c)%1000;
		} else if (a == 4) {
			reg[b] = (reg[b]*c)%1000;
		} else if (a == 5) {
			reg[b] = reg[c];
		} else if (a == 6) {
			reg[b] = (reg[b]+reg[c])%1000;
		} else if (a == 7) {
			reg[b] = (reg[b]*reg[c])%1000;
		} else if (a == 8) {
			reg[b] = ram[reg[c]];
		} else if (a == 9) {
			ram[reg[c]] = reg[b];
		} else if (a == 0) {
			if (reg[c] != 0)
				pos = reg[b]-1;
		}
		else
			throw a;
		pos++;
	}
	printf("%d\n", res);
}
