/*
ID: markus3
TASK: spin
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("spin.out");
ifstream fin ("spin.in");

#define ii pair<int, int>

vector<vector<ii>> wedges;
vector<int> speed;
int tid;

bool hasWedge(int wheel, int pos){
    for (int i = 0; i < wedges[wheel].size(); i++){
        int n1 = wedges[wheel][i].first;
        int n2 = wedges[wheel][i].second;
        n1 += speed[wheel] * tid;
        n2 += speed[wheel] * tid;
        n1 %= 360;
        n2 %= 360;
        if (n1 <= n2 && pos <= n2 && pos >= n1)
            return true;
        if (n1 > n2 && (pos >= n1 || pos <= n2))
            return true;
    }
    return false;
}

int main() {
    wedges.assign(5, vector<ii>());
    speed.assign(5, 0);
    for (int i = 0; i < 5; i++){
        fin >> speed[i];
        int w; fin >> w;
        wedges[i].assign(w, ii());
        for (int j = 0; j < w; j++){
            int n1, n2; fin >> n1 >> n2;
            n2 += n1; n2 %= 360;
            wedges[i][j] = ii(n1, n2);
        }
    }
    for (tid = 0; tid < 360; tid++){
        int sucess;
        for (int pos = 0; pos < 360; pos++){
            sucess = true;
            for (int wheel = 0; wheel < 5; wheel++){
                if (!hasWedge(wheel, pos))
                    sucess = false;
            }
            if (sucess) break;
        }
        if (sucess) break;
    }
    if (tid < 360)  fout << tid << endl;
    else            fout << "none" << endl;
}