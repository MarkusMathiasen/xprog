#include <bits/stdc++.h>
using namespace std;

struct car_info {
	int price;
	int pu_cost;
	int km_cost;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		unordered_map<string, car_info> cars;
		for (int i = 0; i < n; i++) {
			string name; cin >> name;
			cin >> cars[name].price >> cars[name].pu_cost >> cars[name].km_cost;
		}
		map<string, int> bills;
		unordered_map<string, bool> inconsistent;
		unordered_map<string, string> having_car;
		for (int i = 0; i < m; i++) {
			int t; string spy_name; char event; cin >> t >> spy_name >> event;
			if (event == 'p') {
				string car_name; cin >> car_name;
				if (having_car[spy_name] != "")
					inconsistent[spy_name] = true;
				bills[spy_name] += cars[car_name].pu_cost;
				having_car[spy_name] = car_name;
			}
			else if (event == 'r') {
				int distance; cin >> distance;
				if (having_car[spy_name] == "")
					inconsistent[spy_name] = true;
				bills[spy_name] += distance * cars[having_car[spy_name]].km_cost;
				having_car[spy_name] = "";
			}
			else if (event == 'a') {
				int severity; cin >> severity;
				if (having_car[spy_name] == "")
					inconsistent[spy_name] = true;
				bills[spy_name] += (99+severity*cars[having_car[spy_name]].price)/100;
			}
			else throw event;
		}
		for (auto& [spy_name,car_name] : having_car)
			if (car_name != "")
				inconsistent[spy_name] = true;
		for (auto& [spy_name,price] : bills) {
			printf("%s ", spy_name.c_str());
			if (inconsistent[spy_name])
				printf("INCONSISTENT\n");
			else
				printf("%d\n", price);
		}
	}
}
