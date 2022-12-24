#include <bits/stdc++.h>
using namespace std;

set<vector<int>> beacons;
vector<vector<vector<int>>> scanners;
vector<bool> vis;
vector<vector<int>> positions;

void swapDir(int i, int dir1, int dir2) {
	for (vector<int>& b : scanners[i])
		swap(b[dir1], b[dir2]),
		b[dir1] = -b[dir1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin, s);
	vector<vector<int>> A;
	while (getline(cin, s)) {
		if (s == "") {
			scanners.push_back(A);
			A.assign(0, vector<int>());
			continue;
		}
		else if (s[2] == '-')
			continue;
		vector<int> b(3, 0); sscanf(s.c_str(), "%d,%d,%d\n", &b[0], &b[1], &b[2]);
		A.push_back(b);
	}
	for (vector<int> b : scanners[0])
		beacons.insert(b);
	vis.assign(scanners.size(), 0);
	vis[0] = true;
	positions.assign(vis.size(), vector<int>());
	positions[0] = {0, 0, 0};
	queue<int> q; q.push(0);
	while (!q.empty()) {
		int sc = q.front(); q.pop();
		for (int i = 1; i < (int)vis.size(); i++) {
			if (vis[i])
				continue;
			set<vector<int>> tried;
			for (int a = 0; a < 4 && !vis[i]; a++) {
				swapDir(i, 0, 1);
				for (int b = 0; b < 4 && !vis[i]; b++) {
					swapDir(i, 0, 2);
					for (int c = 0; c < 4 && !vis[i]; c++) {
						swapDir(i, 1, 2);
						if (tried.count(scanners[i][0]))
							continue;
						tried.insert(scanners[i][0]);
						for (int pa = 0; pa < (int)scanners[sc].size() && !vis[i]; pa++)
							for (int pb = 0; pb < (int)scanners[i].size() && !vis[i]; pb++) {
								vector<int> pos(3, 0);
								for (int k = 0; k < 3; k++)
									pos[k] = scanners[sc][pa][k] - scanners[i][pb][k];
								for (vector<int>& v : scanners[i])
									for (int t = 0; t < 3; t++)
										v[t] += pos[t];
								if (scanners[i][0] == vector<int>{-618, -824, -621})
									if (pos == vector<int>{68, -1246, -43})
										if (scanners[i][1] == vector<int>{-537, -823, -458})
											printf("fundet!\n");
								// check if correct
								int commonCnt = 0;
								bool legal = true;
								vector<bool> v1Match(vis.size(), false);
								vector<bool> v2Match(vis.size(), false);
								for (int v1i = 0; v1i < (int)scanners[sc].size(); v1i++) {
									for (int v2i = 0; v2i < (int)scanners[i].size(); v2i++) {
										if (v2Match[v2i])
											continue;
										if (scanners[sc][v1i] == scanners[i][v2i]) {
											commonCnt++;
											v1Match[v1i] = v2Match[v2i] = true;
											break;
										}
									}
									if (!v1Match[v1i])
										for (int k = 0; k < 3; k++)
											legal &= abs(pos[k] - scanners[i][v1i][k]) > 1000;
								}
								for (int v2i = 0; v2i < (int)scanners[i].size(); v2i++)
									if (!v2Match[v2i])
										for (int k = 0; k < 3; k++)
											legal &= abs(positions[sc][k] - scanners[i][v2i][k]) > 1000;
								if (commonCnt >= 12 && legal) {
									vis[i] = true;
									positions[i] = pos;
									for (vector<int>& beacon : scanners[i])
										beacons.insert(beacon);
									q.push(i);
								}
								if (vis[i])
									break;
								// reverse if not correct
								for (vector<int>& v : scanners[i])
									for (int t = 0; t < 3; t++)
										v[t] -= pos[t];
							}
					}
				}
			}

		}
	}
	printf("hej\n");
	printf("%ld\n", beacons.size());
}
