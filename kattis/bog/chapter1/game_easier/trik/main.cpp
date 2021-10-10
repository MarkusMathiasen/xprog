#include <bits/stdc++.h>
using namespace std;

int pos = 1;
char c;

int main() {
	while (scanf("%c", &c), c != '\n') {
		if (c == 'A') {
			if (pos == 1)
				pos = 2;
			else if (pos == 2)
				pos = 1;
		}
		if (c == 'B') {
			if (pos == 2)
				pos = 3;
			else if (pos == 3)
				pos = 2;
		}
		if (c == 'C') {
			if (pos == 1)
				pos =3;
			else if (pos == 3)
				pos = 1;
		}
	}
	printf("%d\n", pos);
}
