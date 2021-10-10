#include <bits/stdc++.h>

using namespace std;

vector<char> s;
vector<vector<char>> results;

void print(int n){
    for (int i = 0; i < results[n].size(); i++)
        cout << results[n][i];
    cout << endl;
}

int main(){
    char c;
    while (cin >> c)
        s.push_back(c);
    sort(s.begin(), s.end());
    results.push_back(s);
    while (next_permutation(s.begin(), s.end()))
        results.push_back(s);
    cout << results.size() << endl;
    for (int i = 0; i < results.size(); i++)
        print(i);
}