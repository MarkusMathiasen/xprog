#include <bits/stdc++.h>
using namespace std;

struct line {
	int label;
	string cmd;
	string printString;
	char var = '.';
	string a, op = "", b;
	int toLabel;

	line(string& s) {
		stringstream ss(s);
		ss >> label >> cmd;
		getline(ss, s, ' ');
		string rest;
		if (cmd == "PRINT" || cmd == "PRINTLN") {
			getline(ss, rest);
			if ((int)rest.size() == 1)
				var = rest[0];
			else
				printString = rest.substr(1, (int)rest.size()-2);
		}
		else if (cmd == "LET") {
			ss >> var >> rest;
			getline(ss, rest, ' ');
			vector<string> arth;
			while (ss >> rest)
				arth.push_back(rest);
			if ((int)arth.size() == 1)
				a = arth[0];
			else
				a = arth[0], op = arth[1], b = arth[2];
		}
		else if (cmd == "IF") {
			ss >> a >> op >> b >> rest >> rest >> toLabel;
		}
		else throw cmd;
	}
	bool operator < (const line& a) const {
		return label < a.label;
	}
};

unordered_map<int, int> labelToIndex;
vector<line> lines;
vector<int> store(26, 0);

int interpret(string& s) {
	if (isalpha(s[0]))
		return store[s[0]-'A'];
	else
		return stoi(s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (getline(cin, s) && s != "")
		lines.push_back(line(s));
	sort(lines.begin(), lines.end());
	for (int i = 0; i < (int)lines.size(); i++)
		labelToIndex[lines[i].label] = i;
	int index = 0;
	while (index < (int)lines.size()) {
		line& curr = lines[index];
		if (curr.cmd == "LET") {
			int& loc = store[curr.var-'A'];
			if (curr.op == "")
				loc = interpret(curr.a);
			else if (curr.op == "+")
				loc = interpret(curr.a) + interpret(curr.b);
			else if (curr.op == "-")
				loc = interpret(curr.a) - interpret(curr.b);
			else if (curr.op == "*")
				loc = interpret(curr.a) * interpret(curr.b);
			else if (curr.op == "/")
				loc = interpret(curr.a) / interpret(curr.b);
			else throw curr.op;
		}
		else if (curr.cmd == "IF") {
			int a = interpret(curr.a), b = interpret(curr.b);
			bool cond;
			if (curr.op == "=")
				cond = a == b;
			else if (curr.op == ">")
				cond = a > b;
			else if (curr.op == "<")
				cond = a < b;
			else if (curr.op == "<>")
				cond = a != b;
			else if (curr.op == "<=")
				cond = a <= b;
			else if (curr.op == ">=")
				cond = a >= b;
			else throw curr.op;
			if (cond)
				index = labelToIndex[curr.toLabel]-1;
		}
		else if (curr.cmd == "PRINT") {
			if (curr.var == '.')
				printf("%s", curr.printString.c_str());
			else
				printf("%d", store[curr.var-'A']);
		}
		else if (curr.cmd == "PRINTLN") {
			if (curr.var == '.')
				printf("%s\n", curr.printString.c_str());
			else
				printf("%d\n", store[curr.var-'A']);

		}
		else throw curr;
		index++;
	}
}
