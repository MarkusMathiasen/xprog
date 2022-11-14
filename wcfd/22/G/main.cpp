#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	printf("%d ml gin\n", 45*n);
	printf("%d ml fresh lemon juice\n", 30*n);
	printf("%d ml simple syrup\n", 10*n);
	if (n == 1)
		printf("%d slice of lemon\n", n);
	else
		printf("%d slices of lemon\n", n);

}
