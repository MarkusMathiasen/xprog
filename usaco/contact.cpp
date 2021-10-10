/*
ID: markus3
TASK: contact
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("contact.out");
ifstream fin ("contact.in");

#define is pair<int, string>

int A, B, N;
char seq[200012];
map<string, int> m;

bool compare(is p1, is p2) {return (p1 > p2);}

int main() {
    fin >> A >> B >> N;
    memset(seq, '#', sizeof(seq));
    for (int i = 0; fin >> seq[i]; i++) continue;

    for (int i = 0; i < 200000; i++){
        if (seq[i] == '#') break;
        string s;
        for (int j = 0; j <= 12; j++){
            if (seq[i+j] == '#') break;
            s.push_back(seq[i+j]);
            if (j+1 < A || j+1 > B) continue;
            if (!m.count(s)) m[s] = 0;
            m[s]++;
        }
    }
    priority_queue<is> Q;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
        Q.push(is(it->second, it->first));
    int prev = -1;
    vector<vector<is>> results(N, vector<is>());
    vector<int> length(N, -1);

    for (int i = 0; i <= N; i++){
        if (Q.empty()) break;
        int l = Q.top().first;
        string s = Q.top().second;
        Q.pop();
        if (l == prev){
            i--;
            results[i].push_back(is(s.size(), s));
        }
        else {
            if (i == N) break;
            results[i].push_back(is(s.size(), s));
            length[i] = l;
            prev = l;
        }
    }
    for (int i = 0; i < results.size(); i++){
        sort(results[i].begin(), results[i].end(), compare);
        if (length[i] == -1) break;
        fout << length[i];
        int count = 5;
        for (int j = results[i].size()-1; j >= 0; j--){
            count++;
            if (count == 6) {
                count = 0;
                fout << endl << results[i][j].second;
            }
            else {
                fout << " " << results[i][j].second;
            }
        }
        fout << endl;
    } 
}