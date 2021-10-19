#include <bits/stdc++.h>
using namespace std;
#define si pair<string, int>

struct person {
	string fname, lname;
	string id;
	vector<si> tim = {si("", -1), si("", -1), si("", -1)};
	person(string& fname, string& lname, string& id) : fname(fname), lname(lname), id(id) {}
	person() {}
	bool operator < (const person& a) const {
		if (lname != a.lname)
			return lname < a.lname;
		else
			return fname < a.fname;
	}
	string name() {
		return lname + ", " + fname;
	}
};

void makeRanks(vector<person*>& ranks, int idx) {
	sort(ranks.begin(), ranks.end(), [idx](const person* a, const person* b) {
		return (a->tim)[idx].first < (b->tim)[idx].first;
	});
	(ranks[0]->tim)[idx].second = 1;
	for (int i = 1; i < (int)ranks.size(); i++)
		if ((ranks[i]->tim)[idx].first == (ranks[i-1]->tim)[idx].first)
			(ranks[i]->tim)[idx].second = (ranks[i-1]->tim)[idx].second;
		else
			(ranks[i]->tim)[idx].second = i+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n, n) {
		map<string, person> persons;
		for (int i = 0; i < n; i++) {
			string fname, lname, id; cin >> fname >> lname >> id;
			persons[id] = person(fname, lname, id);
		}
		for (int i = 0; i < 3*n; i++) {
			string id, type, tim; cin >> id >> type >> tim;
			person& r = persons[id];
			if (type == "S1")
				r.tim[0].first = tim;
			else if (type == "S2")
				r.tim[1].first = tim;
			else if (type == "F")
				r.tim[2].first = tim;
			else throw type;
		}
		vector<person*> ranks;
		for (auto& [k,v] : persons)
			ranks.push_back(&v);
		makeRanks(ranks, 0);
		makeRanks(ranks, 1);
		makeRanks(ranks, 2);
		printf("%-20s%10s%10s%10s%10s%10s%10s%10s\n",
			"NAME", "BIB", "SPLIT1", "RANK", "SPLIT2", "RANK", "FINISH", "RANK");
		vector<person> res;
		for (auto& [k,v] : persons)
			res.push_back(v);
		sort(res.begin(), res.end());
		for (person& p : res)
			printf("%-20s%10s%10s%10d%10s%10d%10s%10d\n", 
				p.name().c_str(), p.id.c_str(),
				p.tim[0].first.c_str(), p.tim[0].second,
				p.tim[1].first.c_str(), p.tim[1].second,
				p.tim[2].first.c_str(), p.tim[2].second);
		printf("\n");
	}
}
