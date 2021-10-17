#include <bits/stdc++.h>
using namespace std;

vector<int> store(26, 0);
int lineNumber = 0;
unordered_map<int, int> labelToIndex;

int interpret(string& s, bool& isConst) {
	if (isalpha(s[0])) {
		isConst = false;
		return s[0]-'A';
	}
	else {
		isConst = true;
		return stoi(s);
	}
}

struct Statement {
	int label;
	Statement(const int label) : label(label) {}
	virtual void execute() = 0;
};

struct Assignment : Statement {
	int varIndex;
	bool isConst1 = true, isConst2 = true;;
	int val1, val2;
	char op = 'x';
	
	Assignment(int label, string& str) : Statement(label) {
		stringstream ss(str);
		string trash, x;
		char var;
		ss >> var >> trash >> x;
		varIndex = var-'A';
		val1 = interpret(x, isConst1);
		if (ss >> op >> x)
			val2 = interpret(x, isConst2);
	}
	void execute() override {
		int a = isConst1 ? val1 : store[val1];
		int b = isConst2 ? val2 : store[val2];
		if (op == 'x')
			store[varIndex] = a;
		else if (op == '+')
			store[varIndex] = a+b;
		else if (op == '-')
			store[varIndex] = a-b;
		else if (op == '*')
			store[varIndex] = a*b;
		else if (op == '/')
			store[varIndex] = a/b;
		else throw op;
		lineNumber++;
	}
};

struct Condition : Statement {
	bool isConst1, isConst2;
	int val1, val2;
	string op;
	int toLabel;
	Condition(int label, string& str) : Statement(label) {
		stringstream ss(str);
		string trash, a, b;
		ss >> a >> op >> b >> trash >> trash >> toLabel;
		val1 = interpret(a, isConst1);
		val2 = interpret(b, isConst2);
	}
	void execute() override {
		int a = isConst1 ? val1 : store[val1];
		int b = isConst2 ? val2 : store[val2];
		bool res;
		if (op == "=")
			res = a == b;
		else if (op == ">")
			res = a > b;
		else if (op == "<")
			res = a < b;
		else if (op == "<>")
			res = a != b;
		else if (op == "<=")
			res = a <= b;
		else if (op == ">=")
			res = a >= b;
		else throw op;
		if (res)
			lineNumber = labelToIndex[toLabel];
		else
			lineNumber++;
	}
};

struct Print : Statement {
	bool newline;
	int varIndex = -1;
	string printString;
	Print(int label, string& str, bool newline) : Statement(label), newline(newline) {
		if (str[1] == '"')
			printString = str.substr(2, str.size()-3);
		else
			varIndex = str[1]-'A';
	}
	void execute() override {
		if (varIndex != -1)
			cout << store[varIndex];
		else
			cout << printString;
		if (newline)
			cout << '\n';
		lineNumber++;
	}
};
vector<unique_ptr<Statement>> lines;

void parse() {
	int label;
	string cmd, str;
	while (cin >> label >> cmd) {
		getline(cin, str);
		if (cmd == "LET")
			lines.push_back(make_unique<Assignment>(label, str));
		else if (cmd == "IF")
			lines.push_back(make_unique<Condition>(label, str));
		else if (cmd == "PRINT" || cmd == "PRINTLN")
			lines.push_back(make_unique<Print>(label, str, cmd == "PRINTLN"));
		else throw cmd;
	}
	sort(lines.begin(), lines.end(), [](const unique_ptr<Statement>& a, const unique_ptr<Statement>& b) {
			return a->label < b->label;
			});
	for (int i = 0; i < (int)lines.size(); i++)
		labelToIndex[lines[i]->label] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	parse();
	while (lineNumber < (int)lines.size())
		lines[lineNumber]->execute();
}
