/*
ID: markus3
TASK: prefix
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

ofstream fout ("prefix.out");
ifstream fin ("prefix.in");

vector<vector<string>> prefixes(11, vector<string>());
vector<char> S;
vector<bool> isPossible;

bool canExdend(int start, int end){
    int l = end-start;
    for (int i = 0; i < prefixes[l].size(); i++){
        bool word = true;
        for (int j = 0; j < l; j++)
            if (prefixes[l][i].at(j) != S[start+j+1]){
                word = false;
                break;
            }
        if (word) return true;
    }
    return false;
}


int main() {
    string prefix; fin >> prefix;
    while (prefix != "."){
        prefixes[prefix.length()].push_back(prefix);
        fin >> prefix;
    }
    char next;
    while (fin >> next)
        S.push_back(next);
    isPossible.assign(S.size(), 0);
    for (int i = 0; i < S.size(); i++){
        int sstart = i-10; // search start
        sstart = max(sstart, -1);
        while (sstart < i){
            if (sstart == -1 || isPossible[sstart])
                if (canExdend(sstart, i)){
                    isPossible[i] = true;
                    break;
                }
            sstart++;
        }
    }
    int result = isPossible.size()-1;
    while (result >= 0 && !isPossible[result]) result--;
    result++;
    fout << result << endl;
}