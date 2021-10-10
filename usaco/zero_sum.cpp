/*
ID: markus3
TASK: zerosum
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");

int N;

bool isZero(vector<int> &ops){
    vector<int> nums;
    nums.push_back(1);
    for (int i = 0; i < ops.size(); i++){
        if (ops[i] == 0){
            nums.back() *= 10;
            nums.back() += i+2;
        }
        else {
            nums.push_back(i+2);
        }
    }
    int sum = nums[0];
    int opsIn = 0;
    for (int i = 1; i < nums.size(); i++){
        while (ops[opsIn] == 0) opsIn++;
        if (ops[opsIn] == 1) sum += nums[i];
        if (ops[opsIn] == 2) sum -= nums[i];
        opsIn++;
    }
    return (sum == 0);
}
bool next(vector<int> &ops, int pos){
    if (pos < 0) return false;
    if (ops[pos] == 2){
        ops[pos] = 0;
        return next(ops, pos-1);
    }
    ops[pos]++;
    return true;
}

int main() {
    fin >> N;
    vector<int> ops(N-1, 0);
    vector<vector<int>> results;
    ops[N-2] = -1;
    while(next(ops, N-2))
        if (isZero(ops))
            results.push_back(ops);
    for (int i = 0; i < results.size(); i++){
        fout << 1;
        for (int j = 0; j < results[i].size(); j++){
            if (results[i][j] == 0) fout << " ";
            if (results[i][j] == 1) fout << "+";
            if (results[i][j] == 2) fout << "-";
            fout << j+2;
        }
        fout << endl;
    }
}