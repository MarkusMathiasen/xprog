#include <bits/stdc++.h>
using namespace std;

string fat, oth;
double fatsum = 0, othsum = 0;
int rowcount = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> fat) {
		if (fat != "-") {
			rowcount++;
			int fatper = 0, othper = 0, fatcal = 0, othcal = 0;
			int fatnum = stoi(fat.substr(0, fat.size()-1));
			if (fat.back() == '%')
				fatper = fatnum;
			else if (fat.back() == 'C')
				fatcal = fatnum;
			else fatcal = fatnum*9;
			for (int i = 0; i < 4; i++) {
				cin >> oth;
				int othnum = stoi(oth.substr(0, oth.size()-1));
				if (oth.back() == '%')
					othper += othnum;
				else if (oth.back() == 'C')
					othcal += othnum;
				else
					othcal += othnum*(i == 3 ? 7 : 4);
			}
			int persum = 100 - fatper - othper;
			int calsum = fatcal + othcal;
			fatsum += (double)(fatper*calsum)/persum;
			othsum += (double)(othper*calsum)/persum;
			fatsum += fatcal;
			othsum += othcal;
		}
		else if (rowcount) {
			int res = round(100*fatsum/(fatsum+othsum));
			printf("%d%%\n", res);
			fatsum = othsum = rowcount = 0;
		}
	}

}
