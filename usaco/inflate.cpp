/*
ID: markus3
TASK: inflate
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("inflate.out");
ifstream fin ("inflate.in");

#define ii pair<int, int>
#define fii pair<float, ii>

int M, N;
vector<fii> type;
int bestResult = 0;

int bestPoints(int pos, int minLeft, int pEarned){
    if (pos == N) return 0;
    int p = type[pos].second.first;                 //Points for current type
    int m = type[pos].second.second;                //Minutes for current type
    int maxP = type[pos].first * minLeft + pEarned; //Max points I can earn, if I only use current type
    if (maxP < bestResult) return 0;                //Return if I can't do better
    int stay = pEarned;
    if (m <= minLeft)
        stay = bestPoints(pos, minLeft-m, pEarned+p);       //What is the best if I take 1 more of current type?
    int leave = bestPoints(pos+1, minLeft, pEarned);        //What is the best if I skip current type?
    int result = max(stay, leave);                          //Choose the best of those
    bestResult = max(bestResult, result);
    return result;
}

int main() {
    fin >> M >> N;
    type.assign(N, fii(0, ii(0, 0)));
    for (int i = 0; i < N; i++){
        fin >> type[i].second.first;    //Points  (Value)
        fin >> type[i].second.second;   //Minutes (Cost)
        type[i].first = type[i].second.first / (float) type[i].second.second;
    }
    sort(type.begin(), type.end(), greater<fii>());
    fout << bestPoints(0, M, 0) << endl;
    cout << "test" << endl;

}