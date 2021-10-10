#include <bits/stdc++.h>  //nr. 10004 problem
using namespace std;

vector<vector<int>> graph;
vector<int> colors;

bool coloringImpossible(int node){
    for (int i = 0; i < graph[node].size(); i++){
        int nabo = graph[node][i];
        int myColor = colors[node];
        if (colors[nabo] == colors[node]) return false;
        if (colors[nabo] == 0) {
            colors[nabo] = myColor * (-1);
            if (coloringImpossible) return true;
        }
    }
    return false;
}

int main(){
    int n, l;
    cin >> n;
    while (n != 0){
        cin >> l;
        graph.resize(0);  graph.resize(n, vector<int>() );
        colors.resize(0); colors.resize(n, 0);
        for (int i = 0; i < l; i++){
            int n1, n2; cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        colors[0] = 1;
        if (coloringImpossible(0)) cout << "NOT BICOLORABLE" << endl;
        else cout << "BICOLORABLE" << endl;

        cin >> n;
    }
}