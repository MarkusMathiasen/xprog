#include <bits/stdc++.h>
using namespace std;
#define is pair<int, string>

vector<is> commands;
unordered_map<int, int> toIndex;
unordered_map<string, int> store;

int interpret(string s) {
	if (isalpha(s[0]))
		return store[s];
	else
		return stoi(s);
}

void print(stringstream& ss) {
	string s;
	getline(ss, s, ' ');
	getline(ss, s, '"');
	if (s == "") {
		getline(ss, s, '"');
		printf("%s", s.c_str());
	}
	else
		printf("%d", store[s]);
}

void storeInit() {
	string s = "A";
	for (int i = 'A'; i <= 'Z'; i++) {
		s[0] = i;
		store[s] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int label; string line;
	while (cin >> label) {
		getline(cin, line, ' ');
		getline(cin, line);
		commands.push_back(is(label, line));
	}
	storeInit();
	sort(commands.begin(), commands.end());
	for (int i = 0; i < (int)commands.size(); i++)
		toIndex[commands[i].first] = i;
	int index = 0;
	while (index < (int)commands.size()) {
		is command = commands[index];
		stringstream ss(command.second);
		string cmd; ss >> cmd;
		if (cmd == "LET") {
			string var; ss >> var >> cmd;
			vector<string> ar;
			while (ss >> cmd)
				ar.push_back(cmd);
			if ((int)ar.size() == 1)
				store[var] = interpret(ar[0]);
			else {
				int x = interpret(ar[0]);
				int y = interpret(ar[2]);
				if (ar[1] == "+")
					store[var] = x + y;
				else if (ar[1] == "-")
					store[var] = x - y;
				else if (ar[1] == "*")
					store[var] = x * y;
				else if (ar[1] == "/")
					store[var] = x / y;
				else throw ar;
			}
		}
		else if (cmd == "IF") {
			string X, op, Y; ss >> X >> op >> Y;
			bool cond;
			int x = interpret(X);
			int y = interpret(Y);
			if (op == "=")
				cond = x == y;
			else if (op == ">")
				cond = x > y;
			else if (op == "<")
				cond = x < y;
			else if (op == "<>")
				cond = x != y;
			else if (op == "<=")
				cond = x <= y;
			else if (op == ">=")
				cond = x >= y;
			else throw op;
			if (cond) {
				int label;
				ss >> cmd >> cmd >> label;
				index = toIndex[label]-1;
			}
		}
		else if (cmd == "PRINT") {
			print(ss);
		}
		else if (cmd == "PRINTLN") {
			print(ss);
			printf("\n");
		}
		else throw cmd;
		index++;
	}
}
