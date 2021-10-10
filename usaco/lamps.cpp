/*
ID: markus3
TASK: lamps
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<int> on, off;
ofstream fout ("lamps.out");
ifstream fin ("lamps.in");

vector<bool> even(vector<bool> k){for (int i = 1; i < k.size(); i += 2)   k[i] = !k[i]; return k;}
vector<bool> uneven(vector<bool> k){for (int i = 0; i < k.size(); i += 2) k[i] = !k[i]; return k;}
vector<bool> all(vector<bool> k){for (int i = 0; i < k.size(); i++) k[i] = !k[i]; return k;}
vector<bool> third(vector<bool> k){for (int i = 0; i < k.size(); i += 3) k[i] = !k[i]; return k;}

bool isValid(vector<bool> k){
    for (int i = 0; i < on.size(); i++)
        if (!k[on[i]])  return false;
    for (int i = 0; i < off.size(); i++)
        if (k[off[i]])  return false;
    return true;
}

void printS(vector<bool> k){
    for (int i = 0; i < k.size(); i++)
        fout << k[i];
    fout << endl;
}

int main() {
    fin >> N >> C;
    int next; fin >> next;
    while (next != -1)
        on.push_back(next-1), fin >> next;
    fin >> next;
    while (next != -1)
        off.push_back(next-1), fin >> next;
    
    vector<bool> state(N, 1);
    vector<bool> allS = all(state);
    vector<bool> evenS = even(state);
    vector<bool> unevenS = uneven(state);
    vector<bool> thirdS = third(state);
    vector<bool> allThird = third(allS);
    vector<bool> evenThird = third(evenS);
    vector<bool> unevenThird = third(unevenS);
    vector<vector<bool>> results;
    if (C > 0){
        if (isValid(allS)) results.push_back(allS);
        if (isValid(evenS)) results.push_back(evenS);
        if (isValid(unevenS)) results.push_back(unevenS);
        if (C != 2 && isValid(thirdS)) results.push_back(thirdS);
        if (C > 1){
            if (isValid(state)) results.push_back(state);
            if (isValid(allThird)) results.push_back(allThird);
            if (isValid(evenThird)) results.push_back(evenThird);
            if (isValid(unevenThird)) results.push_back(unevenThird);
        }
    } else{
        if (isValid(state)) results.push_back(state);
    }
    sort(results.begin(), results.end());
    for (int i = 0; i < results.size(); i++)
        printS(results[i]);
    if (results.size() == 0)
        fout << "IMPOSSIBLE" << endl;
}