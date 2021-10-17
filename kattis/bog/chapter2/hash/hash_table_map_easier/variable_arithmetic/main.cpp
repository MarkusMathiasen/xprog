#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string, int> store;
	string line;
	while (getline(cin, line), line != "0") {
		stringstream ss(line);
		vector<string> tokens;
		string s;
		while (ss >> s)
			tokens.push_back(s);
		if (tokens.size() > 1 && tokens[1] == "=") {
			store[tokens[0]] = stoi(tokens[2]);
			continue;
		}
		int sum = 0;
		vector<string> res;
		for (string token : tokens) {
			if (token == "+")
				continue;
			else if (isdigit(token[0]))
				sum += stoi(token);
			else if (store.count(token))
				sum += store[token];
			else
				res.push_back(token);
		}
		if (!res.size())
			printf("%d\n", sum);
		else {
			if (sum)
				printf("%d", sum);
			for (int i = 0; i < (int)res.size(); i++) {
				if (i != 0 || sum)
					printf(" + ");
				printf("%s", res[i].c_str());
			}
			printf("\n");
		}
	}
}
