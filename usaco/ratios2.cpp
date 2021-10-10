/*
ID: markus3
TASK: ratios
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("ratios.out");
ifstream fin ("ratios.in");

int goal[3], r[3][3];
bool found = false;

int calcRat(int num, int type){
    if (goal[type] == 0)
            return -1; //It's fine no matter what
    return (num / goal[type]);
}
bool possible(int num, int type){
    if (goal[type] == 0){
        if (num != 0) return false;
        if (num == 0) return true;
    }
    if (num % goal[type])
        return false;
    return true;
}

int main() {
    for (int i = 0; i < 3; i++)
        fin >> goal[i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            fin >> r[i][j];
    for (int a = 0; a < 100; a++)
        for (int b = 0; b < 100; b++)
            for (int c = 0; c < 100; c++){
                if (found) break;
                bool cool = true;
                int n[3];
                n[0] = r[0][0]*a+r[1][0]*b+r[2][0]*c;
                n[1] = r[0][1]*a+r[1][1]*b+r[2][1]*c;
                n[2] = r[0][2]*a+r[1][2]*b+r[2][2]*c;
                for (int i = 0; i < 3; i++)
                    if (!possible(n[i], i))
                        cool = false;
                int res = -1;
                for (int i = 0; i < 3; i++){
                    int k = calcRat(n[i], i);
                    if (k == -1) continue;
                    if (res == -1) res = k;
                    if (k == res) continue;
                    cool = false;
                }
                if (res == 0) cool = false;
                if (cool){
                    found = true;
                    fout << a << " " << b << " " << c << " " << res << endl;
                }
            }
    if (!found)
        fout << "NONE" << endl;
}