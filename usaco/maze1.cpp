/*
ID: markus3
TASK: maze1
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("maze1.out");
ifstream fin ("maze1.in");

int W, H;
vector<vector<int>> graph;
vector<int> dist;
vector<int> start;

int main() {
    fin >> W >> H;
    graph.assign(W*H, vector<int>());
    dist.assign(W*H, 0);
    int c; string s;
    getline(fin, s); getline(fin, s);
    for (int i = 0; i < W; i++){
        c = i*2+1;
        if (s[c] == ' ')
            start.push_back(i);
    }
    for (int i = 0; i < H; i++){
        c = 0;
        getline(fin, s);
        if (s[c] == ' ')
            start.push_back(W*i);
        for (int j = 0; j < W-1; j++){
            c += 2;
            int v1 = i*W+j;
            int v2 = i*W+j+1;
            if (s[c] == ' '){
                graph[v1].push_back(v2);
                graph[v2].push_back(v1);
            }
        }
        c += 2;
        if (s[c] == ' ') start.push_back((i+1)*W-1);
        if (i != H-1){
            c = -1;
            getline(fin, s);
            for (int j = 0; j < W; j++){
                c += 2;
                int v1 = i*W+j;
                int v2 = (i+1)*W+j;
                if (s[c] == ' '){
                    graph[v1].push_back(v2);
                    graph[v2].push_back(v1);
                }
            }
        }
    }
    for (int i = 0; i < W; i++){
        c = 2*i+1;
        getline(fin, s);
        if (s[c] == ' ')
            start.push_back((H-1)*W+i);
    } // NU ER INPUT LÆST!

    queue<pair<int, int>> Q;
    int result = 0;
    for (int i = 0; i < start.size(); i++)
        Q.push(make_pair(start[i], 1));
    while (!Q.empty()){
        int v = Q.front().first;
        int l = Q.front().second;
        Q.pop();
        if (dist[v]) continue;
        dist[v] = l;
        for (int i = 0; i < graph[v].size(); i++)
            Q.push(make_pair(graph[v][i], l+1));
        result = max(result, l);
    }
    fout << result << endl;
}