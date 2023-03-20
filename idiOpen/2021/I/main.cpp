#include <bits/stdc++.h>

using namespace std;

int Y, X;
vector<vector<int>> image;
vector<vector<int>> lineMax;
vector<int> numCount;

int getB(int y, int x) {
	if (y == 0)
		return 0;
	return image[y-1][x];
}
int getA(int y, int x) {
	if (x == 0)
		return 0;
	return image[y][x-1];
}
void update(int l) {
	for (int i = 0; i < 256; i++)
		lineMax[l][i] = max(lineMax[l][i], numCount[i]);
}

int main() {
	cin >> Y >> X;
	image.assign(Y, vector<int>(X, 0));
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			scanf("%d", &image[y][x]);
		}
	}
	lineMax.assign(Y, vector<int>(256, 0));
	for (int l = 0; l < Y; l++) {
		numCount.assign(256, 0);
		for (int x = 0; x < X; x++)
			numCount[image[l][x]]++;
		update(l);
		numCount.assign(256, 0);
		for (int x = 0; x < X; x++) {
			int b = image[l][x] - getA(l, x);
			if (b < 0) b += 256;
			numCount[b]++;
		}
		update(l);
		numCount.assign(256, 0);
		for (int x = 0; x < X; x++) {
			int b = image[l][x] - getB(l, x);
			if (b < 0) b += 256;
			numCount[b]++;
		}
		update(l);
		numCount.assign(256, 0);
		for (int x = 0; x < X; x++) {
			int b = image[l][x] - ((getA(l, x) + getB(l, x))%256)/2;
			if (b < 0) b += 256;
			numCount[b]++;
		}
		update(l);
	}
	int resByte = -1;
	int resAmount = 0;
	for (int b = 255; b >= 0; b--) {
		int bAmount = 0;
		for (int l = 0; l < Y; l++)
			bAmount += lineMax[l][b];
		if (resAmount < bAmount) {
			resByte = b;
			resAmount = bAmount;
		}
	}
	cout << resByte << " " << resAmount << endl;
}
