#include <bits/stdc++.h>
using namespace std;

vector<double> pitches(12, 0);
set<int> nodes;
vector<int> nodeInts;
vector<set<int>> scales(5, set<int>());
int n;

void printNode(int node, int scale) {
	if (node == 0)
		printf("A\n");
	else if (node == 1)
		printf("Bb\n");
	else if (node == 2)
		printf("B\n");
	else if (node == 3)
		printf("C\n");
	else if (node == 4)
		printf("C#\n");
	else if (node == 5)
		printf("D\n");
	else if (node == 6)
		printf("Eb\n");
	else if (node == 7)
		printf("E\n");
	else if (node == 8)
		printf("F\n");
	else if (node == 9)
		printf("F#\n");
	else if (node == 10)
		printf("G\n");
	else if (node == 11)
		printf(scale == 2 ? "Ab\n" : "G#\n");
	else
		throw node;
}

int main() {
	for (int i = 0; i < 12; i++)
		pitches[i] = 440*pow(2, i/12.0);
	scanf("%d", &n);
	while (n--) {
		double freq; scanf("%lf", &freq);
		bool found = false;
		for (int i = 0; i < 12; i++) {
			double mod = pitches[i];
			while (mod < freq)
				mod *= 2;
			while (mod > freq)
				mod /= 2;
			if (mod-1e-4 <= freq && freq <= mod+1e-4) {
				nodes.insert(i);
				nodeInts.push_back(i);
				found = true;
				break;
			}
			else if (mod*2-1e-4 <= freq && freq <= mod*2+1e-4) {
				nodes.insert(i);
				nodeInts.push_back(i);
				found = true;
				break;
			}
		}
		if (!found) {
			printf("cannot determine key\n");
			return 0;
		}
	}
	scales[0] = {0, 2, 3, 5, 7, 9, 10};
	scales[1] = {3, 5, 7, 8, 10, 0, 2};
	scales[2] = {6, 8, 10, 11, 1, 3, 5};
	scales[3] = {9, 11, 0, 2, 4, 5, 7};
	scales[4] = {10, 0, 1, 3, 5, 6, 8};
	int sum = 0;
	int scale = -1;
	for (int i = 0; i < 5; i++)
		if (includes(scales[i].begin(), scales[i].end(), nodes.begin(), nodes.end()))
			sum++, scale = i;
	if (sum != 1) {
		printf("cannot determine key\n");
		return 0;
	}
	else if (scale == 0)
		printf("G major\n");
	else if (scale == 1)
		printf("C major\n");
	else if (scale == 2)
		printf("Eb major\n");
	else if (scale == 3)
		printf("F# minor\n");
	else if (scale == 4)
		printf("G minor\n");
	else throw scale;
	for (int x : nodeInts)
		printNode(x, scale);
}
