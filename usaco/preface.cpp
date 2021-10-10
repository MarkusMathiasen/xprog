/*
ID: markus3
TASK: preface
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> req(3501, vector<int>(7, 0));

vector<int> sumVec(vector<int> v1, vector<int> v2){
    vector<int> result(v1.size());
    for (int i = 0; i < result.size(); i++)
        result[i] = v1[i] + v2[i];
    return result;
}

vector<int> findVec(int i){
    if (req[i][0] != -1) return req[i];
    if (i > 1000) req[i] = sumVec(req[1000], findVec(i-1000));
    else if(i > 900) req[i] = sumVec(req[900], findVec(i-900));
    else if(i > 500) req[i] = sumVec(req[500], findVec(i-500));
    else if(i > 400) req[i] = sumVec(req[400], findVec(i-400));
    else if(i > 100) req[i] = sumVec(req[100], findVec(i-100));
    else if(i > 90) req[i] = sumVec(req[90], findVec(i-90));
    else if(i > 50) req[i] = sumVec(req[50], findVec(i-50));
    else if(i > 40) req[i] = sumVec(req[40], findVec(i-40));
    else if(i > 10) req[i] = sumVec(req[10], findVec(i-10));
    else if(i > 5) req[i] = sumVec(req[5], findVec(i-5));
    else if(i > 1) req[i] = sumVec(req[1], findVec(i-1));

    return req[i];
}

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    fin >> n;
    for (int i = 0; i < 3501; i++)
        req[i][0] = -1;
    req[0][0] = 0;
    req[1][0] = 1;
    req[4][0] = 1; req[4][1] = 1;
    req[5][0] = 0; req[5][1] = 1;
    req[9][0] = 1; req[9][2] = 1;
    req[10][0] = 0; req[10][2] = 1;
    req[40] = {0, 0, 1, 1, 0, 0, 0};
    req[50] = {0, 0, 0, 1, 0, 0, 0};
    req[90] = {0, 0, 1, 0, 1, 0, 0};
    req[100] = {0, 0, 0, 0, 1, 0, 0};
    req[400] = {0, 0, 0, 0, 1, 1, 0};
    req[500] = {0, 0, 0, 0, 0, 1, 0};
    req[900] = {0, 0, 0, 0, 1, 0, 1};
    req[1000] = {0, 0, 0, 0, 0, 0, 1};

    vector<int> result = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 1; i <= n; i++)
        result = sumVec(result, findVec(i));

    if (result[0]) fout << "I " << result[0] << endl;
    if (result[1]) fout << "V " << result[1] << endl;
    if (result[2]) fout << "X " << result[2] << endl;
    if (result[3]) fout << "L " << result[3] << endl;
    if (result[4]) fout << "C " << result[4] << endl;
    if (result[5]) fout << "D " << result[5] << endl;
    if (result[6]) fout << "M " << result[6] << endl;
}