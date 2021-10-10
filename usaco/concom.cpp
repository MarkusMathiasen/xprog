/*
ID: markus3
TASK: concom
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("concom.out");
ifstream fin ("concom.in");

int owns[100][100];
int og[100][100];
bool controls[100][100];

void findOwns(int comp){
    bool didSomething = true;
    while (didSomething){
        didSomething = false;
        for (int i = 0; i < 100; i++){
            if (i == comp) continue;
            if (controls[comp][i]) continue;
            if (owns[comp][i] > 50){
                controls[comp][i] = true;
                didSomething = true;
                for (int j = 0; j < 100; j++)
                    owns[comp][j] += og[i][j];
            }
        }
    }
}

int main() {
    int n; fin >> n;
    for (int i = 0; i < n; i++){
        int a, b, p; fin >> a >> b >> p; a--; b--;
        owns[a][b] += p;
        og[a][b] += p;
    }
    for (int i = 0; i < 100; i++)
        findOwns(i);
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (owns[i][j] > 50 && i != j)
                fout << i+1 << " " << j+1 << endl;
}