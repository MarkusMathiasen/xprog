#include <bits/stdc++.h>
using namespace std;

int a, b, la, lb, lx, ab;

int len(int x) {
	int t = 1, i;
	for (i = 0; t <= x; i++)
		t *= 10;
	return i;
}
int getDiget(int x, int d) {
	int t = 1;
	for (int i = 1; i < d; i++)
		t *= 10;
	return (x%(t*10))/t;
}

void printTop() {
	printf("+-");
	for (int i = 0; i < la; i++)
		printf("----");
	printf("--+\n");
}
void printMid() {
	printf("| ");
	for (int i = 0; i < la; i++)
		printf("+---");
	printf("+ |\n");
}

int main() {
	while (scanf("%d%d", &a, &b), a || b) {
		la = len(a); lb = len(b);
		int mid[lb][la];
		for (int r = 0; r < lb; r++)
			for (int c = 0; c < la; c++) {
				int da = getDiget(a, la-c);
				int db = getDiget(b, lb-r);
				mid[r][c] = da*db;
			}
		lx = len(a*b);
		ab = a*b;
		// Top line
		printTop();

		// Top number
		printf("|   ");
		for (int i = 0; i < la; i++)
			printf("%d   ", getDiget(a, la-i));
		printf("|\n");

		// Mid section
		for (int r = 0; r < lb; r++) {
			// Line 1
			printMid();
			// Line 2
			printf("|");
			printf(lx > lb+la-r ? "/" : " ");
			for (int c = 0; c < la; c++)
				printf("|%d /", mid[r][c]/10);
			printf("| |\n");
			// Line 3
			printf("| |");
			for (int c = 0; c < la; c++)
				printf(" / |");
			printf("%d|\n", getDiget(b, lb-r));
			// Line 4
			printf("|");
			if (lx >= lb+la-r)
				printf("%d", getDiget(ab, lb+la-r));
			else
				printf(" ");
			for (int c = 0; c < la; c++)
				printf("|/ %d", mid[r][c]%10);
			printf("| |\n");
		}
		printMid();
		printf(lx > la ? "|/" : "| ");
		for (int c = 0; c < la-1; c++)
			printf(" %d /", getDiget(ab, la-c));
		printf(" %d    |\n", ab%10);

		printTop();
	}
}
