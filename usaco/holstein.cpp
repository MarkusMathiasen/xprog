/*
ID: markus3
TASK: holstein
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

int V, G, n = 16, vits;
vector<int> req;            //required
vector<vector<int>> vit;    //vitamins

int calcN(int i){
    if (!i) return 0;
    int result = 1;
    while (i -= (i & (-i)))result++;
    return result;
}
bool isEnough(int i){
    vector<int> sum(V);
    for (int k = 0; k < G; k++)
        if (i & (1 << k))
            for (int j = 0; j < V; j++)
                sum[j] += vit[k][j];
    for (int j = 0; j < V; j++)
        if (sum[j] < req[j]) return false;
    return true;
}

int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    fin >> V;
    for (int i = 0; i < V; i++)
        {int val; fin >> val; req.push_back(val);}
    fin >> G;
    for (int i = 0; i < G; i++){
        vector<int> scoop;
        for (int j = 0; j < V; j++)
            {int val; fin >> val; scoop.push_back(val);}
        vit.push_back(scoop);
    }
    int comb = pow(2, G);
    for (int i = 0; i < comb; i++){
        int newN = calcN(i);
        if (newN < n && isEnough(i))
            vits = i, n = newN;
    }
    fout << n;
    for (int k = 0; k < G; k++)
        if (vits & (1 << k))
            fout << " " << k+1;
    fout << endl;
}