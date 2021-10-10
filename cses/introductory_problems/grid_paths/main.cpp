#include <bits/stdc++.h>

using namespace std;

bool vis[7][7];
char rules[48];

bool valid(int i, int j){
	if (i >= 7 || j >= 7 || i < 0 || j < 0) return false;
	if (vis[i][j]) return false;
	return true;
}
bool hasOneWay(int i, int j){
	if (i == 6 && j == 0) return false;
	if (!valid(i, j)) return false;
	int vCount = 0;
	if (valid(i+1, j)) vCount++;
	if (valid(i-1, j)) vCount++;
	if (valid(i, j+1)) vCount++;
	if (valid(i, j-1)) vCount++;
	return (vCount == 1);
}

int dfs(int i, int j, int c){
	if (!valid(i, j)) return 0;
	if ((i == 0 || i == 6) && valid(i, j+1) && valid(i, j-1)) return 0;
	if ((j == 0 || j == 6) && valid(i+1, j) && valid(i-1, j)) return 0;
	if (i == 6 && j == 0){
		if (c == 48)
			return 1;
		return 0;
	}
	if (hasOneWay(i+1, j+1)) return 0;
	if (hasOneWay(i+1, j-1)) return 0;
	if (hasOneWay(i-1, j+1)) return 0;
	if (hasOneWay(i-1, j-1)) return 0;
	
	vis[i][j] = true;
	int result = 0;
	if (rules[c] != '?'){
		if (rules[c] == 'U') result = dfs(i-1, j, c+1);
		else if (rules[c] == 'D') result = dfs(i+1, j, c+1);
		else if (rules[c] == 'L') result = dfs(i, j-1, c+1);
		else if (rules[c] == 'R') result = dfs(i, j+1, c+1);
		vis[i][j] = false;
		return result;
	}
	result += dfs(i+1, j, c+1);
	result += dfs(i-1, j, c+1);
	result += dfs(i, j+1, c+1);
	result += dfs(i, j-1, c+1);
	vis[i][j] = false;
	return result;
}

int main(){
	for (int i = 0; i < 48; i++)
		scanf("%c", &rules[i]);
	printf("%d\n", dfs(0, 0, 0));
}
