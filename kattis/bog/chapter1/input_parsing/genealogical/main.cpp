#include <bits/stdc++.h>
using namespace std;

map<string, string> birth, death;
map<string, set<string>> kids, par;
void trim(string& s) {
	while (s.back() == ' ')
		s.pop_back();
	while (s.front() == ' ')
		s.erase(0, 1);
}

void indent(int x) {
	for (int i = 0; i < x; i++)
		printf(" ");
}

void printTree(string p, int x, map<string, set<string>>& tree) {
	indent(x);
	printf("%s", p.c_str());
	if (birth.count(p)) {
		printf(" %s -", birth[p].c_str());
		if (death.count(p))
			printf(" %s", death[p].c_str());
	}
	printf("\n");
	for (string nxt : tree[p])
		printTree(nxt, x+2, tree);
}

int main() {
	string cmd;
	bool prev = false;
	while (cin >> cmd) {
		if (cmd == "BIRTH") {
			string child; getline(cin, child, ':'); trim(child);
			string day; getline(cin, day, ':'); trim(day);
			string mom; getline(cin, mom, ':'); trim(mom);
			string dad; getline(cin, dad); trim(dad);
			birth[child] = day;
			par[child].insert(mom);
			par[child].insert(dad);
			kids[mom].insert(child);
			kids[dad].insert(child);
		} else if (cmd == "DEATH") {
			string pers; getline(cin, pers, ':'); trim(pers);
			string day; getline(cin, day); trim(day);
			death[pers] = day;
		} else if (cmd == "ANCESTORS") {
			if (prev)
				printf("\n");
			string pers; getline(cin, pers); trim(pers);
			printf("ANCESTORS of %s\n", pers.c_str());
			for (string p : par[pers])
				printTree(p, 2, par);
			prev = true;
		} else if (cmd == "DESCENDANTS") {
			if (prev)
				printf("\n");
			string pers; getline(cin, pers); trim(pers);
			printf("DESCENDANTS of %s\n", pers.c_str());
			for (string p : kids[pers])
				printTree(p, 2, kids);
			prev = true;
		} else if (cmd == "QUIT")
			return 0;
		else
			throw cmd;
	}
}
