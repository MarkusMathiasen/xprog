#include <bits/stdc++.h>

using namespace std;

int n;
int to[200000];
int results[200000];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &to[i]), to[i]--;
	for (int i = 0; i < n; i++){
		if (results[i]) continue;
		int pos = to[i];
		int d = 1;
		vector<int> parts(1, i);
		while (pos != i){
			d++;
			parts.push_back(pos);
			pos = to[pos];
		}
		for (int j = 0; j < parts.size(); j++)
			results[parts[j]] = d;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", results[i]);
	printf("\n");
}
