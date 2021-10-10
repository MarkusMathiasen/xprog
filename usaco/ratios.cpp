/*
ID: markus3
TASK: ratios
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("ratios.out");
ifstream fin ("ratios.in");

int goal[3], rations[3][3];

int main() {
    for (int i = 0; i < 3; i++)
        fin >> goal[i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            fin >> rations[i][j];

    int resSum = 400;
    int bestI, bestJ, bestK, ratio;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++){
                if (!(i || j || k)) continue;
                int n0 = rations[0][0]*i+rations[1][0]*j+rations[2][0]*k;
                int n1 = rations[0][1]*i+rations[1][1]*j+rations[2][1]*k;
                int n2 = rations[0][2]*i+rations[1][2]*j+rations[2][2]*k;
                if ((!(n0 && goal[0]) || n0 % goal[0] == 0) && ((!n1 && goal[1]) || n1 % goal[1] == 0) && ((!(n2 && goal[2]) || n2 % goal[2] == 0)))
                    if (n0 / goal[0] == n1 / goal[1] && n1 / goal[1] == n2 / goal[2])
                        if (resSum > i+j+k){
                            resSum = i+j+k;
                            bestI = i; bestJ = j; bestK = k;
                            ratio = n0 / goal[0];
                        }
            }
    if (resSum < 400)
        fout << bestI << " " << bestJ << " " << bestK << " " << ratio << endl;
    else
        fout << "none" << endl;
}