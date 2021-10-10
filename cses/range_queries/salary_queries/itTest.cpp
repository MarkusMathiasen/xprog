#include <bits/stdc++.h>

using namespace std;

int main(){
	map<int, int> m;
	m[0] = 3;
	m[1] = 4;
	m[2] = -1;
	m[3] = 3;
	m[4] = 7;
	map<int, int>::iterator it = m.lower_bound(2);
	cout << *it << endl;
	//printf("%d\n", it - m.begin());
}
