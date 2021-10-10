/*
ID: markus3
TASK: ttwo
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("ttwo.out");
ifstream fin ("ttwo.in");

bool walls[10][10];
int farmPos[3], cowPos[3], startFarm[3], startCow[3]; //0 = x, 1 = y, 2 = dir (where 0 is N, 1 is E, 2 is S and 3 is W)

void move(int p[]){
    if (p[2] == 0){
        if (p[1] == 9) p[2]++;
        else if (walls[p[0]][p[1]+1]) p[2]++;
        else p[1]++;
    }
    else if (p[2] == 2){
        if (p[1] == 0) p[2]++;
        else if (walls[p[0]][p[1]-1]) p[2]++;
        else p[1]--;
    }
    else if (p[2] == 1){
        if (p[0] == 9) p[2]++;
        else if (walls[p[0]+1][p[1]]) p[2]++;
        else p[0]++;
    }
    else if (p[2] == 3){
        if (p[0] == 0) p[2] = 0;
        else if (walls[p[0]-1][p[1]]) p[2] = 0;
        else p[0]--;
    }
}

bool isFound(){
    for (int i = 0; i < 2; i++)
        if (farmPos[i] != cowPos[i])
            return false;
    return true;
}

int main() {
    for (int i = 9; i >= 0; i--)
        for (int j = 0; j < 10; j++){
            char c; fin >> c;
            if (c == '*')
                walls[j][i] = true;
            if (c == 'F')
                farmPos[0] = startFarm[0] = j, farmPos[1] = startFarm[1] = i;
            if (c == 'C')
                cowPos[0] = startCow[0] = j, cowPos[1] = startCow[1] = i;
        }
    
    int result = 0;

    while (!isFound()){
        move(farmPos);
        move(cowPos);
        result++;
        if (result > 158400){result = 0; break;}
    }
    fout << result << endl;
}