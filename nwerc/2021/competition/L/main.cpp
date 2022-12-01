#include <bits/stdc++.h>
using namespace std;

int main() {
	double n, i, k; scanf("%lf%lf%lf", &n, &i, &k);
	double res = pow((i-1)/n, k)*i;
	for (double j = i; j <= n; j++)
		res += (pow(j/n, k) - pow((j-1)/n, k)) * (j+1)/2.0;
	printf("%lf\n", res);
}
