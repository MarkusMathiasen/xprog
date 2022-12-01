#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int a, b; cin >> a >> b;
	vector<string> v(b-a+1, "");
	for (int i = a; i <= b; i++)
		cin >> v[i-a];
	int fizz = 0;
	int fizzval = b+1;
	for (int i = a; i <= b; i++)
		if (v[i-a] == "Fizz" || v[i-a] == "FizzBuzz")
			fizzval = i - fizz,
			fizz = i;
	int buzz = 0;
	int buzzval = b+1;
	for (int i = a; i <= b; i++)
		if (v[i-a] == "Buzz" || v[i-a] == "FizzBuzz")
			buzzval = i - buzz,
			buzz = i;
	printf("%d %d\n", fizzval, buzzval);
}
