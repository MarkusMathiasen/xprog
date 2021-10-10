#include <bits/stdc++.h>
using namespace std;

vector<char> order = {'G', 'F', 'E', 'D', 'C', 'B', 'A', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
set<char> line = {'F', 'D', 'B', 'g', 'e', 'a'};
vector<string> nodes;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	nodes.assign(n, "");
	for (int i = 0; i < n; i++)
		cin >> nodes[i];
	for (int i = 0; i < 14; i++) {
		printf("%c: ", order[i]);
		char sp = line.count(order[i]) ? '-' : ' ';
		for (int nodeNum = 0; nodeNum < (int) nodes.size(); nodeNum++) {
			string s = nodes[nodeNum];
			char node; int len = 1;
			if (s.size() > 1)
				sscanf(s.c_str(), "%c%d", &node, &len);
			else
				sscanf(s.c_str(), "%c", &node);
			for (int j = 0; j < len; j++)
				printf("%c", node == order[i] ? '*' : sp);
			if (nodeNum+1 != (int)nodes.size())
				printf("%c", sp);
		}
		printf("\n");
	}
}
